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
const int V=300100;
struct Node
{
    int l,r,s;
}tr[4*V];
void init(int id,int l,int r)
{
    tr[id].l=l;
    tr[id].r=r;
    tr[id].s=0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(id*2,l,mid);
    init(id*2+1,mid+1,r);
}
void update(int id,int pos,int v)
{
    if(tr[id].l==pos&&tr[id].r==pos)
    {
        tr[id].s=v;
        return;
    }
    int mid=(tr[id].l+tr[id].r)/2;
    if(pos<=mid)update(id*2,pos,v);
    else update(id*2+1,pos,v);
    tr[id].s=tr[id*2].s+tr[id*2+1].s;
}
int read(int id,int l,int r)
{
    if(tr[id].l==l&&tr[id].r==r)
    return tr[id].s;
    int mid=(tr[id].l+tr[id].r)/2;;
    if(r<=mid)return read(id*2,l,r);
    else if(l>mid)return read(id*2+1,l,r);
    else
    {
        int ret=0;
        ret+=read(id*2,l,mid);
        ret+=read(id*2+1,mid+1,r);
        return ret;
    }
}
int a[V],pos[V],n,Q,op,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        init(1,1,n);
        for(int i=1;i<n;i++)
        if(pos[i+1]>pos[i])update(1,i,1);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op==1)
            {
                printf("%d\n",y-x+1-read(1,x,y-1));
            }
            else
            {
                swap(pos[a[x]],pos[a[y]]);
                swap(a[x],a[y]);
                if(a[x]!=1)
                {
                    if(pos[a[x]-1]<x)update(1,a[x]-1,1);
                    else update(1,a[x]-1,0);
                }
                if(a[y]!=1)
                {
                    if(pos[a[y]-1]<y)update(1,a[y]-1,1);
                    else update(1,a[y]-1,0);
                }
                if(a[x]!=n)
                {
                    if(x<pos[a[x]+1])update(1,a[x],1);
                    else update(1,a[x],0);
                }
                if(a[y]!=n)
                {
                    if(y<pos[a[y]+1])update(1,a[y],1);
                    else update(1,a[y],0);
                }
            }
        }
    }
    return 0;
}