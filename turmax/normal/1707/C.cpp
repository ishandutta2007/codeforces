#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector<int> a[maxn];vector<int> b[maxn];int corn[maxn];int u1[maxn];set<pair<int,int> > t;vector<pair<int,int> > v;int par[maxn];bool used[maxn];int tin[maxn];int tout[maxn];int timer=0;int u[maxn][20];int pr[maxn];int w[maxn];int sub[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x; int ans=get(par[x]);par[x]=ans;return ans;
}
void dfs(int x)
{
    used[x]=true;for(int i=1;i<20;++i) u[x][i]=u[u[x][i-1]][i-1]; tin[x]=timer;++timer;for(int v:b[x]) if(!used[v]) {corn[v]=corn[x]+1;pr[v]=x;u[v][0]=x;dfs(v);} ++timer;tout[x]=timer;used[x]=false;
}
void dfs2(int x)
{
    used[x]=true;sub[x]=w[x];for(int v:b[x]) if(!used[v]) {u1[v]+=u1[x];dfs2(v);sub[x]+=sub[v];} used[x]=false;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
int lca(int x,int y)
{
    if(pred(x,y)) return x;
    if(pred(pr[x],y)) return pr[x];
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i],y))
        {
            return lca(u[x][i-1],y);
        }
    }
    assert(false);
}
int go(int x,int len)
{
    if(len==0) return x;
    if(len==1) return pr[x];
    for(int i=1;i<20;++i)
    {
        if((1<<i)>len)
        {
            return go(u[x][i-1],len-(1<<(i-1)));
        }
    }
    assert(false);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) par[i]=(-1);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);if(get(x)!=get(y)) {t.insert({x,y});par[get(x)]=get(y);b[x].push_back(y);b[y].push_back(x);} v.push_back({x,y});
    }
    dfs(0);
    for(auto [x,y]:v)
    {
        if(t.count({x,y})) continue;
        if(!pred(x,y) && !pred(y,x))
        {
        u1[0]--;u1[x]++;u1[y]++;
        }
        else
        {
        if(!pred(x,y)) swap(x,y);
        u1[y]++;int v=go(y,corn[y]-corn[x]-1);u1[v]--;
        }
    }
    dfs2(0);
    for(int i=0;i<n;++i) if(u1[i]!=0 || sub[i]!=0) cout<<0; else cout<<1;
    return 0;
}