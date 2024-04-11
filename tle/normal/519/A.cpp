#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int bs=0,ws=0,i,j;
    char qp[8][8];
    for(i=0;i<8;i++) cin>>qp[i];
    for(i=0;i<8;i++)
    for(j=0;j<8;j++)
    {
        if(qp[i][j]=='Q') bs+=9; 
        else if(qp[i][j]=='q') ws+=9; 
        else if(qp[i][j]=='R') bs+=5; 
        else if(qp[i][j]=='r') ws+=5;  
        else if(qp[i][j]=='B') bs+=3; 
        else if(qp[i][j]=='b') ws+=3; 
        else if(qp[i][j]=='N') bs+=3; 
        else if(qp[i][j]=='n') ws+=3;
        else if(qp[i][j]=='P') bs+=1; 
        else if(qp[i][j]=='p') ws+=1;
        else if(qp[i][j]=='.') ws+=0;
        else if(qp[i][j]=='K'&&qp[i][j]=='k') ws+=0;                           
    }
    if(ws>bs) cout<<"Black";
    else if(bs>ws) cout<<"White";
    else cout<<"Draw";
}