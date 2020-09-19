#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



bool gameOver = false;
static int chanceNum = 0;
QString chance = "X";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Box1,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box2,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box3,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box4,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box5,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box6,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box7,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box8,SIGNAL(clicked()),this,SLOT(SetTe()));
    connect(ui->Box9,SIGNAL(clicked()),this,SLOT(SetTe()));

    ui->Box1->setChecked(false);
    ui->Box2->setChecked(false);
    ui->Box3->setChecked(false);
    ui->Box4->setChecked(false);
    ui->Box5->setChecked(false);
    ui->Box6->setChecked(false);
    ui->Box7->setChecked(false);
    ui->Box8->setChecked(false);
    ui->Box9->setChecked(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void SetChance()
{
    if(chance == "X")
    {
        chance = "O";
    }
    else
    {
        chance = "X";
    }
}

bool MainWindow:: checkRow()
{
    if(ui->Box1->text()== chance && ui->Box2->text() == chance && ui->Box3->text() == chance )
    {
        gameOver = true;
        return true;
    }
    else if(ui->Box4->text()== chance && ui->Box5->text() == chance && ui->Box6->text() == chance)
    {
        gameOver = true;
        return true;
    }
    else if(ui->Box7->text()== chance && ui->Box8->text() == chance && ui->Box9->text() == chance)
    {
        gameOver = true;
        return true;
    }
    return false;
}
bool MainWindow:: checkCol()
{
    if(ui->Box1->text()==chance && ui->Box4->text()== chance && ui->Box7->text()== chance )
    {
        gameOver = true;
        return true;
    }
    else if(ui->Box2->text()== chance && ui->Box5->text() == chance && ui->Box8->text() == chance )
    {
        gameOver = true;
        return true;
    }
    else if(ui->Box3->text()== chance && ui->Box6->text() == chance && ui->Box9->text() == chance)
    {
        gameOver = true;
        return true;
    }
    return false;
}
bool MainWindow:: checkDia()
{
    if(ui->Box1->text()== chance && ui->Box5->text() == chance && ui->Box9->text() == chance)
    {
        gameOver = true;
        return true;
    }
    else if(ui->Box3->text()== chance && ui->Box5->text()== chance && ui->Box7->text() == chance)
    {
        gameOver = true;
        return true;
    }
    return false;
}
void MainWindow:: logic()
{
    if(checkCol()||checkRow()||checkDia())
    {
        QString winner = chance;
        ui->winner->setText(chance+ " won the game");
    }
}
void MainWindow:: SetTe()
{
    QPushButton *button = (QPushButton *)sender();
    if(!button->isChecked())
    {
      chanceNum++;
      button->setChecked(true);
      button->setText(chance);
      logic();
      if(chanceNum == 9 && gameOver)
      {
          ui->winner->setText("Draw");
      }
      SetChance();
    }

}
