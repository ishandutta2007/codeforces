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
const int V=200100;
const int P=1000000000;
int tr[2][V],N;
void update(int id,int k,int v)
{
    while(k<=N)
    {
        tr[id][k]=(tr[id][k]+v)%P;
        k+=k&-k;
    }
}
int read(int id,int k)
{
    int ret=0;
    while(k)
    {
        ret=(ret+tr[id][k])%P;
        k-=k&-k;
    }
    return ret;
}
int a[3][3],tp[3][3],t[3][3];
int f[V],va[V],op,x,y,n,m;
int main()
{
   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        f[1]=f[2]=1;N=n;
        for(int i=3;i<=n+1;i++)
        f[i]=(f[i-1]+f[i-2])%P;
        memset(tr,0,sizeof(tr));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&va[i]);
            update(0,i,(LL)f[i]*va[i]%P);
            update(1,i,(LL)f[i+1]*va[i]%P);
        }
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                int d=y-va[x];
                va[x]=y;
                int D=d;
                d=(LL)f[x]*D%P;
                if(d<0)d+=P;
                update(0,x,d);
                d=(LL)f[x+1]*D%P;
                if(d<0)d+=P;
                update(1,x,d);
            }
            else
            {
                scanf("%d%d",&x,&y);
                int X=read(0,y)-read(0,x-1);
                int Y=read(1,y)-read(1,x-1);
                if(X<0)X+=P;
                if(Y<0)Y+=P;
                a[0][0]=0;a[0][1]=1;a[1][0]=1;a[1][1]=P-1;
                t[0][0]=t[1][1]=1;t[1][0]=t[0][1]=0;
                while(x)
                {
                    if(x&1)
                    {
                        for(int i=0;i<2;i++)
                        for(int j=0;j<2;j++)
                        {
                            tp[i][j]=0;
                            for(int k=0;k<2;k++)
                            tp[i][j]+=(LL)t[i][k]*a[k][j]%P;
                            tp[i][j]%=P;
                        }
                        for(int i=0;i<2;i++)
                        for(int j=0;j<2;j++)
                        t[i][j]=tp[i][j];
                    }
                    for(int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                    {
                        tp[i][j]=0;
                        for(int k=0;k<2;k++)
                        tp[i][j]+=(LL)a[i][k]*a[k][j]%P;
                        tp[i][j]%=P;
                    }
                    for(int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                    a[i][j]=tp[i][j];
                    x/=2;
                }
                int ret=((LL)Y*t[0][0]%P+(LL)X*t[1][0]%P)%P;
                if(ret<0)ret+=P;
                printf("%d\n",ret);
            }
        }
    }
}