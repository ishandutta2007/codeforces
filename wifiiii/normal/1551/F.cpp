#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
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
        if(k == 2) {
            cout << 1ll * n * (n - 1) / 2 << '\n';
            continue;
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            vector<vector<int>> dep(n, vector<int>(n));
            function<void(int,int)> dfs = [&](int u, int fa) {
                dep[u][0] = 1;
                for(int v : g[u]) {
                    if(v == fa) continue;
                    dfs(v, u);
                    for(int j = 0; j + 1 < n; ++j) dep[u][j + 1] += dep[v][j];
                }
            };
            dfs(i, -1);
            for(int j = 1; j < n; ++j) {
                if(dep[i][j] == 0) break;
                vector<ll> dp(k + 1);
                dp[0] = 1;
                for(int v : g[i]) {
                    if(dep[v][j - 1] == 0) continue;
                    vector<ll> ndp = dp;
                    for(int p = 0; p < k; ++p) {
                        ndp[p + 1] = (ndp[p + 1] + dp[p] * dep[v][j - 1]) % mod;
                    }
                    dp = std::move(ndp);
                }
                ans += dp[k];
            }
        }
        ans %= mod;
        cout << ans << '\n';
    }
}