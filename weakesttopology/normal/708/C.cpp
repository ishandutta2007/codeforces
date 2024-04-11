#include <bits/stdc++.h>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    auto update = [&](int& value, int nvalue) {
        if (nvalue <= N / 2) {
            value = std::max(value, nvalue);
        }
    };
    std::vector<int> w(N), take(N);
    auto dfs = [&](auto &self, int u, int p) -> void {
        w[u] = 1;
        for (auto v : E[u]) {
            if (v == p) continue;
            self(self, v, u);
            update(take[u], w[v]);
            take[u] = std::max(take[u], take[v]);
            w[u] += w[v];
        }
    };
    dfs(dfs, 0, -1);
    std::vector<bool> good(N);
    auto solve = [&](auto& self, int u, int p, int up) -> void {
        int sum = 0;
        good[u] = N - w[u] - up <= N / 2;
        for (auto& v : E[u]) {
            if (v == p) {
                std::swap(v, E[u].back());
            }
            if (v == p) continue;
            if (w[v] - take[v] > N / 2) {
                good[u] = false;
            }
        }
        if (p != -1) {
            E[u].pop_back();
        }
        int deg = E[u].size();
        std::vector<int> pref(deg), suff(deg);
        for (int i = 0; i + 1 < deg; ++i) {
            int v = E[u][i];
            int x = take[v];
            update(x, w[v]);
            pref[i + 1] = std::max(pref[i], x);
            int j = deg - 1 - i;
            int z = E[u][j];
            int y = take[z];
            update(y, w[z]);
            suff[j - 1] = std::max(suff[j], y);
        }
        for (int i = 0; i < deg; ++i) {
            int v = E[u][i];
            int x = std::max({up, pref[i], suff[i]});
            update(x, N - w[v]);
            self(self, v, u, x);
        }
    };
    solve(solve, 0, -1, 0);
    for (int u = 0; u < N; ++u) {
        std::cout << good[u] << "\n "[u + 1 < N];
    }
    exit(0);
}