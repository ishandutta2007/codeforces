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
struct Noc
{
    LL lm,rm,ma,s;
};
Noc Add(Noc x,Noc y)
{
    Noc ret;
    ret.s=x.s+y.s;
    ret.lm=max(x.lm,y.lm+x.s);
    ret.rm=max(y.rm,x.rm+y.s);
    ret.ma=max(x.ma,y.ma);
    ret.ma=max(ret.ma,x.rm+y.lm);
    return ret;
}
LL s[V];
struct Node
{
    int l,r;
    Noc va;
}p[4*V];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    if(l==r)
    {
        p[nu].va.lm=p[nu].va.rm=p[nu].va.s=s[l];
        p[nu].va.ma=max((LL)0,s[l]);return;
    }
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
    p[nu].va=Add(p[nu*2].va,p[nu*2+1].va);
}
Noc read(int nu,int l,int r)
{
    if(p[nu].l==l&&p[nu].r==r)
    return p[nu].va;
    int mid=(p[nu].l+p[nu].r)/2;
    if(r<=mid)return read(nu*2,l,r);
    else if(l>mid)return read(nu*2+1,l,r);
    else
    {
        Noc a=read(nu*2,l,mid);
        Noc b=read(nu*2+1,mid+1,r);
        Noc ret=Add(a,b);
        return ret;
    }
}
int n,m,c,P[V],pos[V],i,x,y;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&c))
    {
        for(i=0;i<n;i++)
        scanf("%d",&pos[i]);
        for(i=0;i<n-1;i++)
        scanf("%d",&P[i]);
        for(i=0;i<n-1;i++)
        s[i]=(LL)(pos[i+1]-pos[i])*50-(LL)c*P[i];
        init(1,0,n-2);
        LL ret=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            Noc tmp=read(1,x-1,y-2);
            ret+=tmp.ma;
        }
        double ans=1.0*ret/100.0;
        printf("%.8f\n",ans);
    }
}