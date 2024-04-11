#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> E(N);
    for (int j = 0; j < M; ++j) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        E[x].push_back(y), E[y].push_back(x);
    }
    int Q;
    std::cin >> Q;
    std::vector<int> a(Q), b(Q), deg(N);
    for (int q = 0; q < Q; ++q) {
        std::cin >> a[q] >> b[q];
        --a[q], --b[q];
        deg[a[q]] ^= 1, deg[b[q]] ^= 1;
    }
    int sum = std::accumulate(deg.begin(), deg.end(), 0);
    if (sum) {
        std::cout << "NO\n" << sum / 2 << '\n';
    } else {
        std::cout << "YES\n";
        std::vector<int> p(N, -1), h(N);
        p[0] = 0;
        auto dfs = [&](auto& self, int u) -> void {
            for (auto v : E[u]) {
                if (p[v] == -1) {
                    p[v] = u;
                    h[v] = h[u] + 1;
                    self(self, v);
                }
            }
        };
        dfs(dfs, 0);
        for (int q = 0; q < Q; ++q) {
            std::vector<int> left, right;
            while (a[q] != b[q]) {
                if (h[a[q]] >= h[b[q]]) {
                    left.push_back(a[q]);
                    a[q] = p[a[q]];
                } else {
                    right.push_back(b[q]);
                    b[q] = p[b[q]];
                }
            }
            left.push_back(a[q]);
            left.insert(left.end(), right.rbegin(), right.rend());
            int K = left.size();
            std::cout << K << '\n';
            for (int k = 0; k < K; ++k) {
                std::cout << left[k] + 1 << "\n "[k + 1 < K];
            }
        }
    }
    exit(0);
}