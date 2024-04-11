#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

using Graph = std::vector<std::vector<int>>;

void solve() {
    int n, m;
    std::cin >> n >> m;

    Edges<int> edges;
    Graph graph(n);

    std::vector<int> ds(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        --u, --v;

        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, c);
        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, c);

        ds[u] += c;
        ds[v] += c;
    }

    std::vector<bool> used(m * 2, false);
    std::queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto ei : graph[v]) {
            if (used[ei ^ 1]) continue;
            used[ei] = true;

            const auto& e = edges[ei];
            int u = e.dst;
            if (u == n - 1) continue;

            ds[u] -= e.cost * 2;
            if (ds[u] == 0) que.push(u);
        }
    }

    for (int i = 0; i < m; ++i) {
        assert(used[i * 2] || used[i * 2 + 1]);
        std::cout << used[i * 2 + 1] << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}