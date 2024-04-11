/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int m,n,x=1;
    cin>>n>>m;
    for(long long int i=0;i<n;i++)
    {
        x=x*2;
        if(m<x)break;
    }
    cout<<(m%x);
    return 0;
}