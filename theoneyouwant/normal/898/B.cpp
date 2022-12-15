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
    int n,a,b;
    cin>>n>>a>>b;
    int counter1=0;
    while(n%a!=0 && n>=0)
    {
        n=n-b;
        counter1++;
    }
    if(n<0)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<n/a<<" "<<counter1;
    }
    return 0;
}