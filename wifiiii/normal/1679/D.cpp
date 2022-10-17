#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    int lo = 1, hi = 1e9 + 7;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        vector<int> vis(n), dp(n); int cyc = 0;
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1; dp[u] = 1;
            for(int v : g[u]) {
                if(a[v] > mid) continue;
                if(vis[v]) {
                    if(vis[v] == 1) cyc = 1;
                    dp[u] = max(dp[u], dp[v] + 1);
                    continue;
                }
                dfs(v);
                dp[u] = max(dp[u], dp[v] + 1);
            }
            vis[u] = 2;
        };
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && a[i] <= mid) {
                dfs(i);
            }
        }
        if(cyc || *max_element(dp.begin(), dp.end()) >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if(lo == 1e9 + 7) cout << -1 << '\n';
    else cout << lo << '\n';
}