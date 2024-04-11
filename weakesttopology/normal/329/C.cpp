#include <bits/stdc++.h>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> E(N);
    for (int j = 0; j < M; ++j) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    auto check = [&](int u, int v) {
        return std::find(E[u].begin(), E[u].end(), v) == E[u].end();
    };
    std::vector<int> V(N);
    std::iota(V.begin(), V.end(), 0);
    for (int t = 0; t < 100; ++t) {
        std::shuffle(V.begin(), V.end(), rng);
        bool good = true;
        std::vector<int> deg(N);
        std::vector<std::array<int, 2>> edges;
        for (int j = 0; j < M; ++j) {
            int r = (j + 1) % N;
            if (!check(V[j], V[r])) {
                good = false;
                break;
            }
            edges.push_back({V[j], V[r]});
            for (auto v : {V[j], V[r]}) {
                ++deg[v];
            }
        }
        if (good) {
            for (auto [u, v] : edges) {
                std::cout << u + 1 << ' ' << v + 1 << std::endl;
            }
            exit(0);
        }
    }
    std::cout << "-1\n";
    exit(0);
}