

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 2e5+5;

vector<int> g0[maxn], g1[maxn];
int c0[maxn], c1[maxn];
int vis[maxn];
vector<int> ps;
void dfs0(int u)
{
    ps.push_back(u);
    c0[u] = 1;
    vis[u] = 1;
    for(int v:g0[u])
    {
        if(vis[v]) continue;
        dfs0(v);
        c0[u] += c0[v];
    }
}
void dfs1(int u)
{
    ps.push_back(u);
    c1[u] = vis[u] = 1;
    for(int v:g1[u])
    {
        if(vis[v]) continue;
        dfs1(v);
        c1[u] += c1[v];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        if(w==1)
        {
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        else
        {
            g0[u].push_back(v);
            g0[v].push_back(u);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        dfs0(i);
        ans += 1ll * c0[i] * (c0[i] - 1);
        for(int v:ps) c0[v] = c0[i];
        ps.clear();
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        dfs1(i);
        ans += 1ll * c1[i] * (c1[i] - 1);
        for(int v:ps) c1[v] = c1[i];
        ps.clear();
    }
    for(int i=1;i<=n;++i) ans += 1ll * (c1[i]-1) * (c0[i]-1);
    cout << ans << endl;
}