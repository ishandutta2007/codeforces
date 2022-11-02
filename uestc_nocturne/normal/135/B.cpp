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
int sq[120],re[120];
struct Point{double x,y;}p[120];
const double eps=1e-9;
double sqr(double x){return x*x;}
bool EQ(double x,double y)
{return x-y<eps&&y-x<eps;}
double Dis(Point x,Point y)
{return sqrt(sqr(x.x-y.x)+sqr(x.y-y.y));}
double d[1200];
bool dfs(int k,int sn,int rn)
{
    if(k==8)
    {
        for(int i=0;i<4;i++)
        for(int j=0;j<i;j++)
        for(int k=0;k<j;k++)
        if(Dis(p[sq[i]],p[sq[j]])+Dis(p[sq[j]],p[sq[k]])==Dis(p[sq[i]],p[sq[k]]))return false;      
        for(int i=0;i<4;i++)
        for(int j=0;j<i;j++)
        for(int k=0;k<j;k++)
        if(Dis(p[re[i]],p[re[j]])+Dis(p[re[j]],p[re[k]])==Dis(p[re[i]],p[re[k]]))return false;
        int ct;
        ct=0;
        for(int i=0;i<4;i++)
        for(int j=0;j<i;j++)
        d[ct++]=Dis(p[sq[i]],p[sq[j]]);
        sort(d,d+ct);
        if(!EQ(d[0],d[3]))return false;
        if(!EQ(d[4],d[5]))return false;
        if(!EQ(2.0*sqr(d[0]),sqr(d[5])))return false;    
        ct=0;
        for(int i=0;i<4;i++)
        for(int j=0;j<i;j++)
        d[ct++]=Dis(p[re[i]],p[re[j]]);
        sort(d,d+ct);
        if(!EQ(d[0],d[1]))return false;
        if(!EQ(d[2],d[3]))return false;
        if(!EQ(d[4],d[5]))return false;
        if(!EQ(sqr(d[0])+sqr(d[2]),sqr(d[5])))return false;
        return true;
    }
    if(sn<4)
    {
        sq[sn]=k;
        if(dfs(k+1,sn+1,rn))return true;
    }
    if(rn<4)
    {
        re[rn]=k;
        if(dfs(k+1,sn,rn+1))return true;
    }
    return false;
}
int main()
{
    while(~scanf("%lf%lf",&p[0].x,&p[0].y))
    {
        for(int i=1;i<8;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(dfs(0,0,0))
        {
            puts("YES");
            for(int i=0;i<4;i++)printf("%d ",sq[i]+1);puts("");
            for(int i=0;i<4;i++)printf("%d ",re[i]+1);puts("");
        }
        else puts("NO");
    }
}