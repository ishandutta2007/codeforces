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
const int V=100100;
const int P=1000000007;
struct Node
{
    int l,r,mx;
    LL s;
}tr[4*V];
int a[V];
void init(int id,int l,int r)
{
    tr[id].l=l;
    tr[id].r=r;
    if(l==r)
    {
        tr[id].mx=tr[id].s=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(2*id,l,mid);
    init(2*id+1,mid+1,r);
    tr[id].mx=max(tr[id*2].mx,tr[id*2+1].mx);
    tr[id].s=tr[id*2].s+tr[id*2+1].s;
}
void mod(int id,int l,int r,int x)
{
    int mid=(tr[id].l+tr[id].r)/2;
    if(tr[id].l==l&&tr[id].r==r)
    {
        if(tr[id].mx<x)return;
        if(l==r)
        {
            tr[id].mx=tr[id].s=tr[id].s%x;
            return;
        }
        else
        {
            mod(id*2,l,mid,x);
            mod(id*2+1,mid+1,r,x);
        }
    }
    else
    {
        if(r<=mid)mod(id*2,l,r,x);
        else if(l>mid)mod(id*2+1,l,r,x);
        else
        {
            mod(id*2,l,mid,x);
            mod(id*2+1,mid+1,r,x);
        }
    }
    tr[id].mx=max(tr[id*2].mx,tr[id*2+1].mx);
    tr[id].s=tr[id*2].s+tr[id*2+1].s;
}
void update(int id,int pos,int x)
{
    if(tr[id].l==pos&&tr[id].r==pos)
    {
        tr[id].mx=tr[id].s=x;
        return;
    }
    int mid=(tr[id].l+tr[id].r)/2;
    if(pos<=mid)update(id*2,pos,x);
    else update(id*2+1,pos,x);
    tr[id].mx=max(tr[id*2].mx,tr[id*2+1].mx);
    tr[id].s=tr[id*2].s+tr[id*2+1].s;
}
LL read(int id,int l, int r)
{
    if(tr[id].l==l&&tr[id].r==r)
    return tr[id].s;
    int mid=(tr[id].l+tr[id].r)/2;
    if(r<=mid)return read(id*2,l,r);
    else if(l>mid)return read(id*2+1,l,r);
    else
    {
        LL a=read(id*2,l,mid);
        LL b=read(id*2+1,mid+1,r);
        return a+b;
    }
}
int n,m,x,y,z,op;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        init(1,1,n);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                cout<<read(1,x,y)<<endl;
            }
            else if(op==2)
            {
                scanf("%d%d%d",&x,&y,&z);
                mod(1,x,y,z);
            }
            else
            {
                scanf("%d%d",&x,&y);
                update(1,x,y);
            }
        }
    }
}