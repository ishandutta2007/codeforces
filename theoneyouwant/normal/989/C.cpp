/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e,b,c,d;
    cin>>e>>b>>c>>d;
    char a[50][50];
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(i%4==0 && j%2==0 && b>1)
            {
                a[i][j]='B';
                b--;
            }
            else if(i%4==1 && j%2==0 && c>0)
            {
                a[i][j]= 'C';
                c--;
            }
            else
            {
                a[i][j]='A';
            }
        }
    }
    e--;
    for(int i=25;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(i%4==0 && j%2==0 && e>0)
            {
                a[i][j]='A';
                e--;
            }
            else if(i%4==1 && j%2==0 && d>0)
            {
                a[i][j]= 'D';
                d--;
            }
            else
            {
                a[i][j]='B';
            }
        }
    }
    cout<<"50 50"<<endl;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
     return 0;
}