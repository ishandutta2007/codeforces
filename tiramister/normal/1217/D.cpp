#include <iostream>
#include <algorithm>
#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst, id;
    Cost cost;
    Edge(int src = -1, int dst = -1, int id = -1, Cost cost = 1)
        : src(src), dst(dst), id(id), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, int id, Cost cost = 1) {
        graph[src].emplace_back(src, dst, id, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }

    int size() const { return graph.size(); }
};

template <class Cost = int>
struct TopologicalSort {
    Graph<Cost> graph;
    std::vector<bool> visited;
    std::vector<int> order, id;

    explicit TopologicalSort(const Graph<Cost>& graph)
        : graph(graph), visited(graph.size(), false), id(graph.size()) {
        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);
        std::reverse(order.begin(), order.end());

        for (int i = 0; i < (int)graph.size(); ++i) id[order[i]] = i;
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        order.push_back(v);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, --u, --v, i);
    }

    TopologicalSort<> tps(graph);
    std::vector<int> ans(m, -1);
    bool isdag = true;

    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            int u = e.dst;
            if (tps.id[v] > tps.id[u]) isdag = false;
            ans[e.id] = (v < u ? 1 : 2);
        }
    }

    if (isdag) {
        std::cout << 1 << std::endl;
        while (m--) std::cout << 1 << " ";
        std::cout << std::endl;
    } else {
        std::cout << 2 << std::endl;
        for (auto a : ans) std::cout << a << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}