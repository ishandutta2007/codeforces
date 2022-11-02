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
struct Node
{
    int l,r,del,s,fs;
}p[2][4*V];
int s[V];
void init(int id,int nu,int l,int r)
{
    p[id][nu].l=l;
    p[id][nu].r=r;
    p[id][nu].s=0;
    p[id][nu].del=0;
    if(id==0)
    p[id][nu].fs=(s[r]-s[l-1]+P)%P;
    else
    p[id][nu].fs=(s[r+1]-s[l]+P)%P;
    //printf("%d %d %d %d\n",nu,l,r,p[id][nu].fs);
    if(l==r)return;
    int mid=(l+r)/2;
    init(id,nu*2,l,mid);
    init(id,nu*2+1,mid+1,r);
}
void update(int id,int nu,int l,int r,int v)
{
    if(p[id][nu].l==l&&p[id][nu].r==r)
    {
        p[id][nu].del=(p[id][nu].del+v)%P;
        p[id][nu].s=(p[id][nu].s+(LL)p[id][nu].fs*v)%P;
        return;
    }
    int mid=(p[id][nu].l+p[id][nu].r)/2;
    if(r<=mid)update(id,nu*2,l,r,v);
    else if(l>mid)update(id,nu*2+1,l,r,v);
    else
    {
        update(id,nu*2,l,mid,v);
        update(id,nu*2+1,mid+1,r,v);
    }
    p[id][nu].s=(p[id][nu*2].s+p[id][nu*2+1].s)%P;
    p[id][nu].s=(p[id][nu].s+(LL)p[id][nu].fs*p[id][nu].del)%P;
}
int read(int id,int nu,int l,int r,int D)
{
    if(p[id][nu].l==l&&p[id][nu].r==r)
    {
        //printf("R %d %d %d %d\n",l,r,D,p[id][nu].s);
        return (p[id][nu].s+(LL)D*p[id][nu].fs)%P;
    }
    int mid=(p[id][nu].l+p[id][nu].r)/2;
    int ret=0;
    if(r<=mid)ret=read(id,nu*2,l,r,(D+p[id][nu].del)%P);
    else if(l>mid)ret=read(id,nu*2+1,l,r,(D+p[id][nu].del)%P);
    else
    {
        ret+=read(id,nu*2,l,mid,(D+p[id][nu].del)%P);
        ret+=read(id,nu*2+1,mid+1,r,(D+p[id][nu].del)%P);
        ret%=P;
    }
    return ret;
}
int tr[V],N;
void Up(int k,int v)
{
    while(k<=N)
    {
        tr[k]=(tr[k]+v)%P;
        k+=k&-k;
    }
}
int Rd(int k)
{
    int ret=0;
    while(k)
    {
        ret=(ret+tr[k])%P;
        k-=k&-k;
    }
    return ret;
}
int a[3][3],tp[3][3],t[3][3];
int f[V],va[V],op,x,y,z,n,m;
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        f[1]=f[2]=1;N=n;
        for(int i=3;i<=n+1;i++)
        f[i]=(f[i-1]+f[i-2])%P;
        s[0]=0;
        for(int i=1;i<=n+1;i++)
        s[i]=(s[i-1]+f[i])%P;
        init(0,1,1,n);
        init(1,1,1,n);
        memset(tr,0,sizeof(tr));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&va[i]);
            update(0,1,i,i,va[i]);
            update(1,1,i,i,va[i]%P);
            Up(i,va[i]);Up(i+1,P-va[i]);
        }
        //for(int i=1;i<=n;i++)printf("%d ",read(0,1,i,i,0));puts("");
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                int d=y-Rd(x);
                if(d<0)d+=P;
                Up(x,d);Up(x+1,P-d);
                update(0,1,x,x,d);
                update(1,1,x,x,d);
            }
            else if(op==3)
            {
                scanf("%d%d%d",&x,&y,&z);
                Up(x,z);Up(y+1,P-z);
                update(0,1,x,y,z);
                update(1,1,x,y,z);
            }
            else
            {
                scanf("%d%d",&x,&y);
                int X=read(0,1,x,y,0);
                int Y=read(1,1,x,y,0);
                //printf("%d %d\n",X,Y);
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