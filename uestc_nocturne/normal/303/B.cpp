/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int gcd(int x,int y)
{
    if(!x)return y;
    if(!y)return x;
    return gcd(y,x%y);
}
int n,m,x,y,a,b;
int main()
{
    while(~scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b))
    {
        int gd=gcd(a,b);
        a/=gd;b/=gd;
        int mi=min(n/a,m/b);
        a*=mi;b*=mi;
        int dx=a/2;
        int dy=b/2;
        if(a%2==1)dx++;
        if(b%2==1)dy++;
        int xl=x-dx;
        int yl=y-dy;
        int xr=xl+a;
        int yr=yl+b;
        if(xl<0)
        {
            xr=a;
            xl=0;
        }
        if(yl<0)
        {
            yr=b;
            yl=0;
        }
        if(xr>n)
        {
            xr=n;
            xl=n-a;
        }
        if(yr>m)
        {
            yr=m;
            yl=m-b;
        }
        printf("%d %d %d %d\n",xl,yl,xr,yr);
    }
}