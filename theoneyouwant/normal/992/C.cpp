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
    long long int x,k;
cin>>x>>k;
    long long int c = pow(10,9)+7;
    if(x==0)
    {
        cout<<"0";
    }
    else
    {
    x=x%c;
    k=k%(c-1);
    long long int two = 1;
    long long int q = pow(2,25);
    q=q%c;
    while(k>25)
    {
        two=two*q%c;
        k=k-25;
    }
    for(int i=0;i<k;i++)
    {
        two=(two*2)%c;
    }
    cout<<(two*(2*x%c)-two+1+c)%c;
    }
     return 0;
}