#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e5+5;
ll l[maxn], r[maxn];
vector<int> g[maxn];
ll dp[maxn][2];
void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = 0;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(l[v] - l[u]), dp[v][1] + abs(r[v] - l[u]));
        dp[u][1] += max(dp[v][0] + abs(l[v] - r[u]), dp[v][1] + abs(r[v] - r[u]));
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;++i) cin>>l[i]>>r[i],g[i].clear();
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
}