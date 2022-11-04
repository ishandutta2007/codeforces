//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;

struct node
{
    int v;
    ll w;
    int next;
}e[6*maxn];
int head[maxn];
int ecnt;
void ae(int u,int v,ll w)
{
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].next=head[u];
    head[u]=ecnt++;
}

ll dis[maxn];
int n,m,k;

struct Date
{
    int u;
    ll dis;
    friend bool operator<(const Date &a,const Date &b)
    {
        return a.dis>b.dis;
    }
};
priority_queue<Date>q;

void dj()
{
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=k;i++)
    {
        dis[i]=0;
        q.push({i,0});
    }
    while(!q.empty())
    {
        auto cur=q.top();
        q.pop();
        int u=cur.u;
        if(cur.dis>dis[u])
            continue;
        for(int i=head[u];~i;i=e[i].next)
        {
            int v=e[i].v;
            if(dis[u]+e[i].w<dis[v])
            {
                dis[v]=dis[u]+e[i].w;
                q.push({v,dis[v]});
            }
        }
    }
}

struct edge
{
    int u,v;
    ll w;
    friend bool operator<(const edge &a,const edge &b)
    {
        return a.w<b.w;
    }
}es[maxn*6];

int f[maxn];
int findx(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=findx(f[x]);
}
map<int,ll>g[maxn];
int vis[maxn],up[maxn][25],dep[maxn];
ll ff[maxn][25];
void dfs(int u)
{
    vis[u]=true;
    for(int i=1,len=1;len<=dep[u];i++,len<<=1)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        ff[u][i]=max(ff[up[u][i-1]][i-1],ff[u][i-1]);
    }
    for(auto x:g[u])
    {
        int v=x.first;
        ll w=x.second;
        if(vis[v])
            continue;
        dep[v]=dep[u]+1;
        up[v][0]=u;
        ff[v][0]=w;
        dfs(v);
    }
}


int query(int u,int v)
{
    if(dep[u]>dep[v])
        swap(u,v);
    int diff=dep[v]-dep[u];
    for(int i=0,two=1;diff!=0;two<<=1,i++)
    {
        if(diff&two)
        {
            v=up[v][i];
            diff-=two;
        }
    }
    if(u==v)
        return u;
    for(int i=log(dep[u])/log(2);i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

ll queryf(int u,int v)
{
    ll ans=0;
    if(dep[u]>dep[v])
    {
        swap(u,v);
    }
    int diff=dep[v]-dep[u];
    for(int i=0,two=1;diff!=0;two<<=1,i++)
    {
        if(diff&two)
        {
            ans=max(ans,ff[v][i]);
            v=up[v][i];
            diff-=two;
        }
    }
    
    if(u==v)
        return ans;
    
    for(int i=log(dep[u])/log(2);i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            ans = max(ans,max(ff[u][i],ff[v][i]));
            u=up[u][i];
            v=up[v][i];
        }
    }
    return max(ans,max(ff[u][0],ff[v][0]));
}



int main()
{
    sync;
    int q;
    memset(head,-1,sizeof(head));
    cin>>n>>m>>k>>q;
    for(int i=0;i<m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        ae(u,v,w);
        ae(v,u,w);
    }
    dj();
    int ec=0;
    for(int u=1;u<=n;u++)
    {
        for(int i=head[u];~i;i=e[i].next)
        {
            int v=e[i].v;
            ll w=e[i].w;
            es[ec++]={u,v,dis[u]+dis[v]+w};
        }
    }
    sort(es,es+ec);
    for(int u=1;u<=n;u++)
        f[u]=u;
    int cnt=0;
    for(int i=0;i<ec&&cnt<n;i++)
    {
        int u=es[i].u;
        int v=es[i].v;
        ll w=es[i].w;
        if(findx(u)==findx(v))
            continue;
        g[u][v]=w;
        g[v][u]=w;
        cnt++;
        f[findx(u)]=findx(v);
    }
    dfs(1);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<queryf(u,v)<<endl;
    }
    
    return 0;
    
   
}