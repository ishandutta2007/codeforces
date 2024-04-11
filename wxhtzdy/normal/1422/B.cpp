#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<std::vector<std::pair<int, int>>>> g(n, std::vector<std::vector<std::pair<int, int>>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j].push_back({n - i - 1, j});
            g[i][j].push_back({i, m - j - 1});
            g[i][j].push_back({n - i - 1, m - j - 1});
        }
    }

    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
    std::vector<int> vals;
    std::function<void(int, int)> dfs = [&](int x, int y) {
        vals.push_back(a[x][y]);
        vis[x][y] = true;
        for (auto e : g[x][y]) {
            if (!vis[e.first][e.second]) {
                dfs(e.first, e.second);
            }
        }
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            vals.clear();
            dfs(i, j);
            std::sort(vals.begin(), vals.end());
            int avg = vals[vals.size() / 2];
            for (int x = 0; x < vals.size(); x++) {
                ans += abs(vals[x] - avg);
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}