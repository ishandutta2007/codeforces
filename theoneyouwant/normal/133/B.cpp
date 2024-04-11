#include<iostream>
#include<cmath>
using namespace std;

const int m = pow(10,6)+3;

int twopower(int n)
{
    int a=1;
    for(int i=0;i<n;i++)
    {
        a=(a*2)%m;
    }
}

int main()
{
    string p;
    cin>>p;
    int total=0,multiplier=1;
    for(int i=p.length()-1;i>=0;i--)
    {
        if(p[i]=='>')
        {
            total+=multiplier*8%m;total%=m;
        }
        else if(p[i]=='<')
        {
            total+=multiplier*9%m;total%=m;
        }
        else if(p[i] == '+')
        {
            total=(total+multiplier*10)%m;total%=m;
        }
        else if(p[i]== '-')
        {
            total=total+multiplier*11%m;
            total%=m;
        }
        else if(p[i]== '.')
        {
            total=total+multiplier*12%m; total%=m;
        }
        else if(p[i]== ',')
        {
            total=total+multiplier*13%m; total%=m;
        }
        else if(p[i]== '[')
        {
            total+=multiplier*14%m; total%=m;
        }
        else
        {
            total+=multiplier*15%m; total%=m;
        }
        multiplier = multiplier*16%m;
    }
    cout<<total%m;
    
    return 0;
}