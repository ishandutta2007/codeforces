#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    int a[k];
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        --a[i];
    }

    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int dist[n][2];
    std::function<void(int, int)> bfs = [&](int st, int k) {
        for (int i = 0; i < n; i++) {
            dist[i][k] = 1E9;
        }
        dist[st][k] = 0;

        std::set<std::pair<int, int>> s;
        s.insert({0, st});

        while (!s.empty()) {
            int u = s.begin() -> second;
            s.erase(s.begin());

            for (int v : e[u]) {
                if (dist[v][k] > dist[u][k] + 1) {
                    s.erase({dist[v][k], v});
                    dist[v][k] = dist[u][k] + 1;
                    s.insert({dist[v][k], v});
                }
            }
        }
    };

    bfs(0, 0);
    bfs(n - 1, 1);

    std::vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return dist[a[i]][0] - dist[a[i]][1] < dist[a[j]][0] - dist[a[j]][1];
    });

    int ans = 0, mx = dist[a[p[0]]][0];
    for (int i = 1; i < k; i++) {
        ans = std::max(ans, dist[a[p[i]]][1] + mx + 1);
        mx = std::max(mx, dist[a[p[i]]][0]);
    }

    std::cout << std::min(ans, dist[n - 1][0]) << "\n";

    return 0;
}