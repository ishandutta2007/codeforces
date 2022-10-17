#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> f(n), a(n), dep(n);
        vector<vector<int>> d(n), g(n);
        for(int i = 1; i < n; ++i) {
            cin >> f[i], --f[i];
            g[f[i]].push_back(i);
        }
        function<void(int)> dfs = [&](int u) {
            d[dep[u]].push_back(u);
            for(int v : g[u]) {
                dep[v] = dep[u] + 1;
                dfs(v);
            }
        };
        dfs(0);
        for(int i = 1; i < n; ++i) cin >> a[i];
        vector<ll> dp(n);
        for(int i = 1; i < n; ++i) {
            if(d[i].empty()) break;
            int mx = -1, mn = 1e9;
            for(int u : d[i]) {
                mx = max(mx, a[u]);
                mn = min(mn, a[u]);
            }
            ll mx2 = -1e18, mx3 = -1e18;
            for(int u : d[i]) {
                mx2 = max(mx2, dp[f[u]] - a[u]);
                mx3 = max(mx3, dp[f[u]] + a[u]);
            }
            for(int u : d[i]) {
                // trans 1
                dp[u] = max(dp[u], dp[f[u]] + max(abs(mx - a[u]), abs(mn - a[u])));
                // trans 2
                dp[u] = max(dp[u], mx2 + a[u]);
                dp[u] = max(dp[u], mx3 - a[u]);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}