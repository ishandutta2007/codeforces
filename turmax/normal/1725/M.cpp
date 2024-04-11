#include <bits/stdc++.h>

using ll = long long;
#define int ll
using namespace std;
struct edge {
    int next, w;
};
template<typename T>
using pqg = priority_queue<T, vector<T>, greater<>>;
int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(2 * n);
    for (int i = 0; i < n; ++i) g[i].push_back({i + n, 0});
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v + n].push_back({u + n, w});
    }
    pqg<pair<ll, int>> dijkstra;
    dijkstra.push({0, 0});
    vector<ll> dist(2 * n, 1e18);
    dist[0] = 0;
    while (!dijkstra.empty()) {
        auto[d, cur] = dijkstra.top();
        dijkstra.pop();
        if (dist[cur] != d) continue;
        for (auto[nxt, w]: g[cur]) {
            if (dist[nxt] > dist[cur] + w) {
                dist[nxt] = dist[cur] + w;
                dijkstra.emplace(dist[nxt], nxt);
            }
        }
    }
    for (int i = 1; i < n; ++i) cout << (dist[i + n] == 1e18 ? -1 : dist[i + n]) << ' ';
}