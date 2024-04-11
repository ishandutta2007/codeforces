#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n);
    vector<int> sz(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        sz[u] = 1;
        int son = 0;
        vector<int> res;
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
            son += 1;
            for(int k = 0;; ++k) {
                if(k == dp[u].size()) dp[u].push_back(0);
                int p = k < dp[v].size() ? dp[v][k] - k : dp[v].back() - k;
                if(p <= 0) {
                    res.push_back(k);
                    break;
                }
                dp[u][k] += p;
            }
        }
        if(dp[u].empty()) dp[u].push_back(0);
        int m = dp[u].size();
        vector<int> c(m + 1);
        for(int i : res) c[i] += 1;
        for(int i = 1; i < m; ++i) c[i] += c[i-1];
        for(int i = 0; i < m; ++i) dp[u][i] += c[i];
    };
    dfs(0, -1);
    int q;
    cin >> q;
    while(q--) {
        int u, k;
        cin >> u >> k;
        --u;
        if(k < dp[u].size()) cout << dp[u][k] << '\n';
        else cout << dp[u].back() << '\n';
    }
}