#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

const int maxd=100000;
int x,y,n,a,b;
int gcd(int x,int y)
{
    while (y)
    {
        int tmp=y;
        y=x%y;
        x=tmp;
    }
    return x;
}
int main()
{
    cin>>x>>y>>a>>b;
    n=x*y/gcd(x,y);
    a=n*((a+n-1)/n);
    if (a<=b) cout<<(1+(b-a)/n);else cout<<0;
}