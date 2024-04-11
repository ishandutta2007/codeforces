#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

vector<pair<int,int>> g[200005];
int ch[200005];
ll w[200005];
int n;
void dfs(int u,int fa)
{
    for(auto &p:g[u])
    {
        int v=p.first;
        if(v==fa) continue;
        w[v]=w[u]+n-2*ch[v];
        p.second=ch[u]-2*ch[v];
        dfs(v,u);
    }
}
void dfs2(int u,int fa)
{
    ch[u]=1;
    for(auto p:g[u])
    {
        int v=p.first;
        if(v==fa) continue;
        dfs2(v,u);
        ch[u]+=ch[v];
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,0});
    }
    dfs2(1,-1);
    dfs(1,-1);
    ll tmp=0;
    forii tmp=max(tmp,w[i]);
    ll ans=0;
    forii ans+=ch[i];
    ans+=tmp;
    cout<<ans<<endl;
}