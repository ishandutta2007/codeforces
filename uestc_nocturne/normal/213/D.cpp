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
const int V=510;
const double Pi=acos(-1.0);
const int N=100;
struct Big
{
    int zs,a[N+2];
    void PT()
    {
        printf("%d.",zs);
        for(int i=0;i<N;i++)
        printf("%d",a[i]);
    }
};
Big To(int x)
{
    Big ret;
    ret.zs=x;
    for(int i=0;i<N;i++)ret.a[i]=0;
    return ret;
}
Big Add(Big x,Big y)
{
    Big ret;
    ret.zs=x.zs+y.zs;
    for(int i=0;i<N;i++)
    ret.a[i]=x.a[i]+y.a[i];
    int jw=0;
    for(int i=N-1;i>=0;i--)
    {
        ret.a[i]+=jw;
        if(ret.a[i]>9)ret.a[i]-=10,jw=1;
        else jw=0;
    }
    ret.zs+=jw;
    return ret;
}
Big tran(char *s)
{
    Big ret;
    ret.zs=s[0]-'0';
    int n=strlen(s);
    for(int i=2;i<n;i++)
    ret.a[i-2]=s[i]-'0';
    for(int i=n-2;i<N;i++)
    ret.a[i]=0;
    return ret;
}
struct Point
{
    Big x,y;
    void PT()
    {
        x.PT();printf(" ");y.PT();puts("");
    }
}p[V];
int n,m,id[]={0,3,1,2};
char s10p[]={"3.0901699437494742410229341718282"};
char c10p[]={"9.5105651629515357211643933337938"};
char s13p[]={"8.0901699437494742410229341718282"};
char c13p[]={"5.8778525229247312916870595463907"};
int main()
{
  //  Big tmp=tran(s10p);tmp.PT();
    while(~scanf("%d",&n))
    {
        m=5*n-n+1;
        p[3*n].y=To(0);p[3*n].x=To(0);
        for(int i=3*n+1;i<m;i++)
        {
            p[i].y=To(0);
            p[i].x=Add(p[i-1].x,tran(s13p));
            p[i].x=Add(p[i].x,tran(s13p));
        }
        p[0].x=tran(s13p);
        p[0].y=tran(c13p);
        for(int i=1;i<n;i++)
        {
            p[i].y=p[i-1].y;
            p[i].x=Add(p[i-1].x,tran(s13p));
            p[i].x=Add(p[i].x,tran(s13p));
        }
        p[n].x=tran(s10p);
        p[n].y=tran(c10p);
        for(int i=n+1;i<2*n;i++)
        {
            p[i].y=p[i-1].y;
            p[i].x=Add(p[i-1].x,tran(s13p));
            p[i].x=Add(p[i].x,tran(s13p));
        }
        p[2*n].x=Add(To(10),tran(s10p));
        p[2*n].y=tran(c10p);
        for(int i=2*n+1;i<3*n;i++)
        {
            p[i].y=p[i-1].y;
            p[i].x=Add(p[i-1].x,tran(s13p));
            p[i].x=Add(p[i].x,tran(s13p));
        }
        printf("%d\n",m);
        for(int i=0;i<m;i++)
        {
            p[i].x.PT();
            printf(" ");
            if(i>=n&&i<3*n)printf("-");
            p[i].y.PT();
            puts("");
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
            printf("%d ",id[j]*n+i+1);
            printf("%d\n",3*n+i+2);
        }
        printf("%d",3*n+1);
        for(int i=1;i<=n;i++)
        printf(" %d",3*n+i+1);
        for(int i=n-1;i>=0;i--)
        printf(" %d %d %d %d",n+i+1,i+1,2*n+i+1,3*n+i+1);
        puts("");
    }
}