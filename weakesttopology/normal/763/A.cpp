#include <bits/stdc++.h>
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
    std::vector<int> c(N);
    for (int u = 0; u < N; ++u) {
        std::cin >> c[u];
    }
    std::vector<int> candidates;
    for (int u = 0; u < N; ++u) {
        bool found = false;
        for (auto v : E[u]) {
            if (c[u] != c[v]) {
                found = true;
                candidates.push_back(u);
                candidates.push_back(v);
                break;
            }
        }
        if (found) break;
    }
    if (candidates.empty()) {
        std::cout << "YES\n1\n";
        exit(0);
    }
    auto dfs = [&](auto& self, int u, int p) -> bool {
        for (auto v : E[u]) {
            if (v == p) continue;
            if (c[u] != c[v] || !self(self, v, u)) {
                return false;
            }
        }
        return true;
    };
    for (auto u : candidates) {
        bool good = true;
        for (auto v : E[u]) {
            if (!dfs(dfs, v, u)) {
                good = false;
                break;
            }
        }
        if (good) {
            std::cout << "YES\n" << u + 1 << '\n';
            exit(0);
        }
    }
    std::cout << "NO\n";
    exit(0);
}