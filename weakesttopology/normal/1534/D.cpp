#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> memo(n);
    auto query = [&](int u) {
        if (not empty(memo[u])) return memo[u];
        ++u;
        cout << "? " << u << endl;
        vector<int> d(n);
        for (auto& x : d) cin >> x;
        return memo[u - 1] = d;
    };
    auto d = query(0);
    vector<vector<int>> C(n);
    int cnt[2]{};
    for (int u = 0; u < n; ++u) {
        C[d[u]].push_back(u);
        ++cnt[d[u] % 2];
    }
    vector<array<int, 2>> edges;
    for (int x = cnt[0] <= cnt[1] ? 0 : 1; x < n; x += 2) {
        for (auto u : C[x]) {
            auto d = query(u);
            for (int v = 0; v < n; ++v) {
                if (d[v] == 1) edges.push_back({u, v});
            }
        }
    }
    cout << "!" << endl;
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << endl;
    }
    exit(0);
}