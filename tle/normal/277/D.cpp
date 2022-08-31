#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,T;
long long mul=1000000;
struct pro
{
int ss,sl,ts,tl;
long double pb;
long long mpb;
}pros[2333];
long long s[1111][1563]; long double t[1111][1563];
bool operator < (pro a,pro b)
{
    if(a.pb+1e-6>1) return 0;
    if(b.pb+1e-6>1) return 1;
    return a.tl*a.pb/(1-a.pb)<b.tl*b.pb/(1-b.pb);
}
int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
    {
        double tmp;
        scanf("%d%d%d%d%lf",&pros[i].ss,&pros[i].sl,&pros[i].ts,&pros[i].tl,&tmp);
        pros[i].pb=tmp;
        pros[i].mpb=pros[i].pb*mul+0.5;
    }
    sort(pros+1,pros+1+n);
    #define UPD(a,b,c,d) {if(b<=T){long long x=c; long double y=d; if(s[a][b]<x||(s[a][b]==x&&t[a][b]>y)) s[a][b]=x, t[a][b]=y;}}
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=T;j++)
        {
            UPD(i+1,j,s[i][j],t[i][j])
            UPD(i+1,j+pros[i].ts,s[i][j]+mul*pros[i].ss,t[i][j]+pros[i].ts)
            UPD(i+1,j+pros[i].ts+pros[i].tl,s[i][j]+mul*pros[i].ss+(mul-pros[i].mpb)*pros[i].sl
            ,(t[i][j]+pros[i].ts)*pros[i].pb+(pros[i].ts+pros[i].tl+j)*(1-pros[i].pb))
        }
    }
    long long anss=-233; long double anst;
    for(int i=0;i<=T;i++)
    {
        long long ss=s[n+1][i]; long double tt=t[n+1][i];
        if(ss>anss||(ss==anss&&tt<anst)) anss=ss, anst=tt;
    }
    long double as=anss,at=anst; as/=1000000.0;
    double aa=as,bb=at;
    printf("%.9lf %.9lf\n",aa,bb);
}