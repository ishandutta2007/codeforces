/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%10<=5)
    {
        n=n-n%10;
    }
    else
    {
        n=n+10-n%10;
    }
    cout<<n;
    return 0;
}