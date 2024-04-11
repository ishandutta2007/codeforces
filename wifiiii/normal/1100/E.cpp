#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
struct edge
{
    int s,t,w,id;
    bool operator < (const edge & e) const
    {
        if(w!=e.w) return w>e.w;
        return id>e.id;
    }
};
vector<int> path;
vector<edge> g[100005];
set<edge> es;
int vis[100005];
int n,m;
int flag;
int dfn[100005];

void dfs(int u, int x)
{
    if(flag) return;
    vis[u] = 1;
    for(int i=0,l=g[u].size();i<l;++i)
    {
        if(g[u][i].w > x)
        {
            if(vis[g[u][i].t]==1) {flag=1;return;}
            dfs(g[u][i].t, x);
        }
    }
    vis[u] = 2;
    return;
}
int chk(int x)
{
    flag = 0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        dfs(i,x);
    }
    memset(vis,0,sizeof(vis));
    return flag==0;
}
int I = 1;
void dfs2(int u,int x)
{
    vis[u] = 1;
    for(int i=0,l=g[u].size();i<l;++i)
    {
        if(g[u][i].w <= x)
        {
            es.insert(g[u][i]);
            continue;
        }
        if(!vis[g[u][i].t]) dfs2(g[u][i].t, x);
    }
    vis[u] = 2;
    dfn[u] = I++;
}
void work(int x)
{
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        dfs2(i,x);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int s,t,w;
        scanf("%d%d%d",&s,&t,&w);
        g[s].push_back((edge){s,t,w,i});
    }
    int lo = 0, hi = 1e9;
    while(lo < hi)
    {
        int mid = (lo + hi) / 2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }
    work(lo);
    for(auto e:es)
    {
        if(dfn[e.s]<dfn[e.t]) path.push_back(e.id);
    }
    sort(path.begin(),path.end());
    cout << lo << " " << path.size() << endl;
    for(int i : path) cout<<i<<" ";
    cout<<endl;
}