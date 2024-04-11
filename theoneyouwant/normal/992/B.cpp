/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

long long int gcd (long long int n1, long long int n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long  int l,r,x,y,count=0;
    cin>>l>>r>>x>>y;
    long double l1 = l/x;
    long long int y1 = y/x;
    long double r1 = r/x;
    if(y%x!=0)
    {
        cout<<"0";
    }
    else
    {
        for(long long int i=1;i<=sqrt(y1);i++)
        {
            if(y1%i==0 && i*x>=l && i*x<=r && y1*x>=l*i && y1*x<=r*i && gcd(i,y1/i)==1)
            {
                count=count+2;
                if(i==y1/i)
                {
                    count--;
                }
            }
        }
        cout<<count;
    }
     return 0;
}