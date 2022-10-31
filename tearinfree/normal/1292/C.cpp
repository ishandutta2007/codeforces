#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,vis[3001],sz[3001],ecnt;
lli dp[3001][3001];
vector<int> adj[3001];
int init(int cur,int p) {
    sz[cur] = 1;
    for(auto &it:adj[cur]) if(it!=p) sz[cur] += init(it,cur);
    return sz[cur];
}
lli DP(int u,int v) {
    lli &ret = dp[u][v];
    if(ret!=-1) return ret;

    ret = 1ll*sz[u]*sz[v]*(ecnt+1);
    for(auto &c:adj[u]) if(!vis[c]) {
        ecnt++;
        vis[c] = 1;
        ret = max(ret, 1ll*(sz[u]-sz[c]) * sz[v] * ecnt + DP(c, v));
        vis[c] = 0;
        ecnt--;
    }
    for(auto &c:adj[v]) if(!vis[c]) {
        ecnt++;
        vis[c] = 1;
        ret = max(ret, 1ll*sz[u] * (sz[v] - sz[c]) * ecnt + DP(u, c));
        vis[c] = 0;
        ecnt--;
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0,u,v;i<n-1;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(dp,-1,sizeof(dp));
    lli ans = 0;
    for(int r=1;r<=n;r++) {
        init(r, 0);
        for(auto &c:adj[r]) {
            sz[r] -= sz[c];
            vis[r] = 1; vis[c] = 1;
            ans = max(ans, DP(r, c));
            vis[r] = 0; vis[c] = 0;
            sz[r] += sz[c];
        }
    }
    printf("%lld\n",ans);
    return 0;
}