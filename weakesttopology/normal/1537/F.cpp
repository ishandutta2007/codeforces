#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> t(n);
        for (int u = 0; u < n; ++u) {
            int x;
            cin >> x;
            t[u] -= x;
        }
        for (int u = 0; u < n; ++u) {
            int x;
            cin >> x;
            t[u] += x;
        }
        bool good = true;
        if (accumulate(begin(t), end(t), 0LL) % 2) good = false;
        vector<vector<int>> E(n);
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[u].push_back(v), E[v].push_back(u);
        }
        vector<int> color(n, -1);
        bool bipartite = true;
        auto dfs = [&](auto& self, int u) -> void {
            for (auto v : E[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    self(self, v);
                }
                else if (color[v] == color[u]) bipartite = false;
            }
        };
        color[0] = 0;
        dfs(dfs, 0);
        if (bipartite) {
            ll sum = 0;
            for (int u = 0; u < n; ++u) {
                sum += (color[u] ? -1 : +1) * t[u];
            }
            if (sum != 0) good = false;
        }
        cout << (good ? "YES" : "NO") << endl;
    }
    exit(0);
}