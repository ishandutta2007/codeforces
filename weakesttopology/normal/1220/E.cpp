#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int u = 0; u < n; ++u) {
        cin >> w[u];
    }
    vector<vector<int>> E(n);
    vector<int> deg(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    int s;
    cin >> s;
    --s;
    queue<int> q;
    for (int u = 0; u < n; ++u) {
        if (u != s && deg[u] == 1) {
            q.push(u);
        }
    }
    vector<bool> dead(n);
    vector<ll> dp(n);
    while (not empty(q)) {
        int u = q.front();
        q.pop();
        dead[u] = true;
        for (auto v : E[u]) {
            dp[v] = max(dp[v], dp[u] + w[u]);
            if (v == s) continue;
            if (--deg[v] == 1) {
                q.push(v);
            }
        }
    }
    ll ans = 0, mx = 0;
    auto dfs = [&](auto& self, int u) -> void {
        ans += w[u], mx = max(mx, dp[u]);
        dead[u] = true;
        for (auto v : E[u]) {
            if (dead[v]) continue;
            self(self, v);
        }
    };
    dfs(dfs, s);
    ans += mx;
    cout << ans << endl;
    exit(0);
}