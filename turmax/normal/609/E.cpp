#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200000;
vector <pair<int,int> > g[maxn];
int parent[maxn];
int lp[maxn];
int glav(int x)
{
    while(true)
    {
        if(parent[x]==(-1))
        {
            return x;
        }
        x=parent[x];
    }
}
void merg(int x,int y)
{
    if(lp[x]>=lp[y])
    {
        parent[y]=x;
        lp[x]+=lp[y];
    }
    else
    {
        parent[x]=y;
        lp[y]+=lp[x];
    }
}
bool used[maxn];
int pr[maxn];
pair <int,int> u[maxn][20];
int timein[maxn];int timeout[maxn];
int timer=0;
void dfs(int x)
{
    for(int i=1;i<20;++i)
    {
        pair <int,int> o=u[x][i-1];
        if(o.first==(-1))
        {
            u[x][i]={-1,-1};
            continue;
        }
        u[x][i].first=u[o.first][i-1].first;
        u[x][i].second=max(o.second,u[o.first][i-1].second);
    }
    timein[x]=timer;
    ++timer;
    used[x]=true;
    int v,w;
    for(int i=0;i<g[x].size();++i)
    {
        v=g[x][i].first;w=g[x][i].second;
        if(!used[v])
        {
        pr[v]=x;
        u[v][0]={x,w};
        dfs(v);
        }
    }
    ++timer;
    timeout[x]=timer;
}
bool pred(int x,int y)
{
    return ((x==(-1)) || (timein[x]<=timein[y] && timeout[x]>=timeout[y]));
}
int lca(int x,int y)
{
    if(x==y)
    {
        return (-1);
    }
    if(pred(x,y))
    {
        return lca(y,x);
    }
    if(pred(pr[x],y))
    {
        return max(u[x][0].second,lca(pr[x],y));
    }
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i].first,y))
        {
            return max(u[x][i-1].second,lca(u[x][i-1].first,y));
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        parent[i]=(-1);
        lp[i]=1;
    }
    vector <pair<int,pair<int,int> > > b;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        b.push_back({w,{x,y}});
    }
    vector <pair<int,pair<int,int> > > b1=b;
    sort(b.begin(),b.end());
    int sum=0;
    for(int i=0;i<b.size();++i)
    {
        int x=glav(b[i].second.first);int y=glav(b[i].second.second);
        if(x!=y)
        {
            merg(x,y);
            g[x].push_back({y,b[i].first});
            g[y].push_back({x,b[i].first});
            sum+=b[i].first;
        }
    }
    pr[0]=(-1);
    u[0][0]={-1,-1};
    dfs(0);
    for(int i=0;i<m;++i)
    {
        pair <int,pair<int,int> > o=b1[i];
        int ans1=lca(o.second.first,o.second.second);
        cout<<(sum-ans1+o.first)<<endl;
    }
    return 0;
}