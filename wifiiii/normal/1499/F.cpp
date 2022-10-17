#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        dp[u].push_back(1);
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            vector<int> nxt_dp(max(dp[u].size(), dp[v].size() + 1));
            // 1. cut the edge
            ll sum = accumulate(dp[v].begin(), dp[v].end(), 0ll) % mod;
            for(int i = 0; i < dp[u].size(); ++i) {
                nxt_dp[i] = (nxt_dp[i] + dp[u][i] * sum) % mod;
            }
            // 2. preserve the edge
            for(int i = 0; i < dp[u].size(); ++i) {
                for(int j = 0; j < dp[v].size(); ++j) {
                    if(i + j + 1 > k) break;
                    nxt_dp[max(i, j + 1)] = (nxt_dp[max(i, j + 1)] + 1ll * dp[u][i] * dp[v][j]) % mod;
                }
            }
            dp[u] = nxt_dp;
        }
    };
    dfs(0, -1);
    ll ans = accumulate(dp[0].begin(), dp[0].end(), 0ll) % mod;
    cout << ans << '\n';
}