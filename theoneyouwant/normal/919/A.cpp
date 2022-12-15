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
    cout<<std::fixed;
    cout<<std::setprecision(9);
    int n,m;
    cin>>n>>m;
    int a,b;
    long double x=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(i==0)
        {
            x=(long double)a/b;
        }
        if((long double)a/b <x)
        {
            x=(long double)a/b;
        }
    }
    cout<<m*x;
    return 0;
}