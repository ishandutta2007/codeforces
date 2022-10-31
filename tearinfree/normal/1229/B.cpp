#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n;
lli cost[100001];
vector<int> adj[100001];

lli ans=0;
const lli MOD = 1e9+7;
void dfs(int cur,int p,vector<pli> ga) {
    ga.push_back({cost[cur],1});
    
    vector<pli> na;
    for(auto &it:ga) it.fi = __gcd(cost[cur],it.fi);
    for(int i = ga.size() - 1;i>=0;i--) {
        if(na.empty() || na.back().fi != ga[i].fi) na.push_back(ga[i]);
        else na.back().se += ga[i].se;
    }
    reverse(na.begin(),na.end());

    for(auto &it:na) ans = (ans + 1ll*it.fi*it.se%MOD)%MOD;
    
    for(auto &it:adj[cur]) if(it!=p) dfs(it,cur,na);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",cost+i);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,vector<pli>());
    printf("%lld\n",ans);
    return 0;
}