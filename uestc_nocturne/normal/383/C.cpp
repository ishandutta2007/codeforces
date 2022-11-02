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
struct Edge{int v,ne;}e[2*V];
int p[V],K;
void add(int u,int v)
{
    e[K].v=v;e[K].ne=p[u];p[u]=K++;
}
struct Node
{
    int l,r,ex[2];
}tr[4*V];
void init(int k,int l,int r)
{
    tr[k].l=l;
    tr[k].r=r;
    tr[k].ex[0]=0;
    tr[k].ex[1]=0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(k*2,l,mid);
    init(k*2+1,mid+1,r);
}
void update(int k,int l,int r,int v,int f)
{
    if(tr[k].l==l&&tr[k].r==r)
    {
        tr[k].ex[f]+=v;
        return;
    }
    int mid=(tr[k].l+tr[k].r)/2;
    if(r<=mid)update(k*2,l,r,v,f);
    else if(l>mid)update(k*2+1,l,r,v,f);
    else
    {
        update(k*2,l,mid,v,f);
        update(k*2+1,mid+1,r,v,f);
    }
}
int read(int k,int pos,int f)
{
    if(tr[k].l==pos&&tr[k].r==pos)
    return tr[k].ex[f];
    int mid=(tr[k].l+tr[k].r)/2;
    if(pos<=mid)return read(k*2,pos,f)+tr[k].ex[f];
    else return read(k*2+1,pos,f)+tr[k].ex[f];
}
int l[V],r[V],a[V],ti,d[V];
void dfs(int u,int fa)
{
    l[u]=ti++;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].v;
        if(v==fa)continue;
        d[v]=1-d[u];
        dfs(v,u);
    }
    r[u]=ti-1;
}
int n,m,op,x,y;
int main()
{
    while(~scanf("%d%D",&n,&m))
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(p,-1,sizeof(p));K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        ti=1;d[1]=0;
        dfs(1,-1);init(1,1,n);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                update(1,l[x],r[x],y,d[x]);
            }
            else
            {
                scanf("%d",&x);
                printf("%d\n",a[x]+read(1,l[x],d[x])-read(1,l[x],1-d[x]));
            }
        }
    }
}