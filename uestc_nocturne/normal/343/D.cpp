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
    int mx;
    int l,r;
}tr[4*V];
void init(int id,int l,int r)
{
    tr[id].l=l;
    tr[id].r=r;
    tr[id].mx=-1;
    if(l==r)return;
    int mid=(l+r)/2;
    init(id*2,l,mid);
    init(id*2+1,mid+1,r);
}
void update(int id,int x,int v)
{
    if(tr[id].l==x&&tr[id].r==x)
    {
        tr[id].mx=v;
        return;
    }
    int mid=(tr[id].l+tr[id].r)/2;
    if(x<=mid)update(id*2,x,v);
    else update(id*2+1,x,v);
    tr[id].mx=max(tr[id*2].mx,tr[id*2+1].mx);
    //printf("%d %d %d %d\n",id,x,v,tr[id].mx);
}
int read(int id,int l,int r)
{
    if(tr[id].l==l&&tr[id].r==r)
    return tr[id].mx;
    int mid=(tr[id].l+tr[id].r)/2;
    if(r<=mid)return read(id*2,l,r);
    else if(l>mid)return read(id*2+1,l,r);
    else
    {
        int a=read(id*2,l,mid);
        int b=read(id*2+1,mid+1,r);
        return max(a,b);
    }
}
Node tr2[4*V];
void init2(int id,int l,int r)
{
    tr2[id].l=l;
    tr2[id].r=r;
    tr2[id].mx=-2;
    if(l==r)return;
    int mid=(l+r)/2;
    init2(id*2,l,mid);
    init2(id*2+1,mid+1,r);
}
void update2(int id,int l,int r,int v)
{
    if(tr[id].l==l&&tr[id].r==r)
    {
        tr2[id].mx=v;
        return;
    }
    int mid=(tr2[id].l+tr2[id].r)/2;
    if(r<=mid) update2(id*2,l,r,v);
    else if(l>mid) update2(id*2+1,l,r,v);
    else
    {
        update2(id*2,l,mid,v);
        update2(id*2+1,mid+1,r,v);
    }
}
int read2(int id,int x)
{
    int ret=tr2[id].mx;
    if(tr2[id].l==tr2[id].r)return ret;
    int mid=(tr2[id].l+tr2[id].r)/2;
    if(x<=mid)ret=max(ret, read2(id*2,x));
    else if(x>mid)ret=max(ret, read2(id*2+1,x));
    return ret;
}
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
int n,Q,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)p[i]=-1;K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        ti=1;dfs(1,-1);
        init(1,1,n);
        init2(1,1,n);
        scanf("%d",&Q);
        for(int tm=1;tm<=Q;tm++)
        {
            scanf("%d%d",&x,&y);
            if(x==1)
            {
                update2(1,l[y],r[y],tm);
            }
            else if(x==2)
            {
                update(1,l[y],tm);
            }
            else
            {
                int fill=read2(1,l[y]);
                int ufill=read(1,l[y],r[y]);
                //cout << fill << " : " << ufill << endl;
                if(fill>ufill)puts("1");
                else puts("0");
            }
        }
    }
}