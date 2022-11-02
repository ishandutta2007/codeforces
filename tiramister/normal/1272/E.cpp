#include <iostream>
#include <vector>
#include <queue>

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
using Graph = std::vector<std::vector<Edge<Cost>>>;

std::vector<int> bfs(const Graph<>& graph,
                     const std::vector<int>& rs) {
    std::vector<int> dist(graph.size(), -1);

    std::queue<int> que;
    for (auto r : rs) {
        que.push(r);
        dist[r] = 0;
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : graph[v]) {
            int u = e.dst;
            if (dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            que.push(u);
        }
    }
    return dist;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    Graph<> rgraph(n);
    for (int v = 0; v < n; ++v) {
        int u = v - xs[v];
        if (u >= 0) rgraph[u].emplace_back(u, v);
        u = v + xs[v];
        if (u < n) rgraph[u].emplace_back(u, v);
    }

    std::vector<int> os, es;
    for (int v = 0; v < n; ++v) {
        (xs[v] % 2 == 0 ? es : os).push_back(v);
    }

    auto odist = bfs(rgraph, os),
         edist = bfs(rgraph, es);
    for (int v = 0; v < n; ++v) {
        std::cout << (xs[v] % 2 == 0 ? odist[v] : edist[v]) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}