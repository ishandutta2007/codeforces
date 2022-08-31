#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef long double ld;
int n,a[233333];
ld g=asin(1)/5;
ld f(ld x)
{
    ld cm=0,maxm=-2000000001,minm=2000000001;
    for(int i=1;i<=n;i++)
    {
        ld A=a[i]+x;
        if(cm<=0) cm=0;
        cm+=A; maxm=max(maxm,cm);
    }
    cm=0;
    for(int i=1;i<=n;i++)
    {
        ld A=a[i]+x;
        if(cm>=0) cm=0;
        cm+=A; minm=min(minm,cm);
    }
    cm=0;
    return max(max(maxm,-minm),cm);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    ld l=-20000.0,r=20000.0;
    for(int i=1;i<=400;i++)
    {
        ld ml=r-l,m1=l+ml*g,m2=r-ml*g;
        ld x1=f(m1),x2=f(m2);
        if(x1>x2) l=m1; else r=m2;
    }
    ld g=f(l);
    double ans=g;
    printf("%.6lf\n",ans);
}