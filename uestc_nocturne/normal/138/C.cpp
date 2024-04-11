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
const int V=500100;
struct Node
{
    int pos;
    double p;
}q[V];
int AB(int x){if(x<0)return -x;return x;}
bool cmp(Node x,Node y)
{
    if(x.pos!=y.pos)return x.pos<y.pos;
    else return x.p<y.p;
}
const double eps=1e-9;
bool EQ(double x,double y)
{
    return x-y<eps&&y-x<eps;
}
struct Seg{int l,r;double p;}p[2*V];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    p[nu].p=1.0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
}
void update(int nu,int l,int r,double P)
{
    if(p[nu].l==l&&p[nu].r==r)
    {p[nu].p*=P;return;}
    int mid=(p[nu].l+p[nu].r)/2;
    if(r<=mid)update(nu*2,l,r,P);
    else if(l>mid)update(nu*2+1,l,r,P);
    else
    {
        update(nu*2,l,mid,P);
        update(nu*2+1,mid+1,r,P);
    }
}
double read(int nu,int po)
{
    if(p[nu].l==po&&p[nu].r==po)
    return p[nu].p;
    double ret=p[nu].p;
    int mid=(p[nu].l+p[nu].r)/2;
    if(po<=mid)ret*=read(nu*2,po);
    else ret*=read(nu*2+1,po);
    return ret;
}
struct Tree{int x,h,l,r;}tr[V];
int ct,n,m,i,x,h,l,r;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ct=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&tr[i].x,&tr[i].h,&tr[i].l,&tr[i].r);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&h);
            q[i].pos=x;q[i].p=1.0*h;
        }
        sort(q,q+m,cmp);
        init(1,0,m-1);
        for(i=0;i<n;i++)
        {
            x=tr[i].x;
            h=tr[i].h;
            l=tr[i].l;
            r=tr[i].r;
            int lo,up,mid,le,ri;
            lo=-1;up=m;
            while(lo+1<up)
            {
                mid=(lo+up)/2;
                if(q[mid].pos<=x-1)lo=mid;
                else up=mid;
            }
            ri=lo;
            lo=-1;up=m;
            while(lo+1<up)
            {
                mid=(lo+up)/2;
                if(q[mid].pos>=x-h)up=mid;
                else lo=mid;
            }
            le=up;
            if(le<=ri&&le>=0&&ri<m)update(1,le,ri,1.0*(100-l)/100);
            lo=-1;up=m;
            while(lo+1<up)
            {
                mid=(lo+up)/2;
                if(q[mid].pos<=x+h)lo=mid;
                else up=mid;
            }
            ri=lo;
            lo=-1;up=m;
            while(lo+1<up)
            {
                mid=(lo+up)/2;
                if(q[mid].pos>=x+1)up=mid;
                else lo=mid;
            }
            le=up;
            if(le<=ri&&le>=0&&ri<m)update(1,le,ri,1.0*(100-r)/100);
        }
        double ret=0.0;
        for(i=0;i<m;i++)
        ret+=read(1,i)*q[i].p;
        printf("%.6f\n",ret);
    }
}