#include <iostream>
#include <vector>
#include <functional>
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
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    // reversed graph
    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, --v, --u);
    }

    std::vector<int> id(n, 0);
    std::vector<int> ans;

    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            int r = id[e.dst];

            if (id[v] == 0 && r == 0) {
                id[v] = 1;
            }

            if (r == 1) {
                id[v] = 2;
            }
        }

        if (id[v] == 2) ans.push_back(v);
    }

    std::cout << ans.size() << "\n";
    for (auto v : ans) std::cout << v + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}