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
struct Edge{int num,ne;}e[2*V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int l[V],r[V],ti;
void dfs(int u,int fa)
{
    l[u]=ti++;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        dfs(v,u);
    }
    r[u]=ti-1;
}
struct Node{int l,r,ct,s;}tr[4*V];
void init(int nu,int l,int r)
{
    tr[nu].l=l;
    tr[nu].r=r;
    tr[nu].ct=tr[nu].s=0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
}
void Up(int nu)
{
    if(tr[nu].ct!=0)tr[nu].s=tr[nu].r-tr[nu].l+1;
    else tr[nu].s=tr[nu*2].s+tr[nu*2+1].s;
}
void update(int nu,int l,int r,int v)
{
    if(tr[nu].l==l&&tr[nu].r==r)
    {
        tr[nu].ct+=v;
        if(l!=r)Up(nu);
        else if(tr[nu].ct==0)tr[nu].s=0;
        else tr[nu].s=1;
        return;
    }
    int mid=(tr[nu].l+tr[nu].r)/2;
    if(r<=mid)update(nu*2,l,r,v);
    else if(l>mid)update(nu*2+1,l,r,v);
    else
    {
        update(nu*2,l,mid,v);
        update(nu*2+1,mid+1,r,v);
    }
    Up(nu);
    //printf("%d %d %d %d %d\n",nu,tr[nu].l,tr[nu].r,tr[nu].s,v);
}
vector<int> id[V];
int ret[V];
void Cal(int u,int fa)
{
    int sz=id[u].size();
    //printf("%d %d\n",u,sz);
    for(int i=0;i<sz;i++)
    update(1,l[id[u][i]],r[id[u][i]],1);
    //printf("%d %d\n",u,sz);
    ret[u]=tr[1].s;
    if(ret[u]!=0)ret[u]--;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(fa==v)continue;
        Cal(v,u);
    }
    for(int i=0;i<sz;i++)
    update(1,l[id[u][i]],r[id[u][i]],-1);
}
int n,m,x,y;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(p,-1,sizeof(p));K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        for(int i=1;i<=n;i++)
        id[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            id[x].push_back(y);
            id[x].push_back(x);
            id[y].push_back(y);
            id[y].push_back(x);
        }
        ti=1;
        dfs(1,-1);
        init(1,1,n);
        Cal(1,-1);
        for(int i=1;i<=n;i++)
        {
            if(i!=1)printf(" ");
            printf("%d",ret[i]);
        }puts("");
    }
}