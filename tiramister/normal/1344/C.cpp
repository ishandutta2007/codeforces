#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>

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
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, --u, --v);
    }

    TopologicalSort<> ts(graph);
    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            if (ts.id[e.src] > ts.id[e.dst]) {
                std::cout << "-1\n";
                return;
            }
        }
    }

    std::vector<int> normal_min(n);
    std::iota(normal_min.begin(), normal_min.end(), 0);

    auto order = ts.order;
    std::reverse(order.begin(), order.end());
    for (auto v : order) {
        for (auto e : graph[v]) {
            normal_min[v] = std::min(normal_min[v], normal_min[e.dst]);
        }
    }

    std::vector<int> reverse_min(n);
    std::iota(reverse_min.begin(), reverse_min.end(), 0);
    std::reverse(order.begin(), order.end());
    for (auto v : order) {
        for (auto e : graph[v]) {
            reverse_min[e.dst] = std::min(reverse_min[v], reverse_min[e.dst]);
        }
    }

    std::string ans(n, 'E');
    for (int v = 0; v < n; ++v) {
        if (v == std::min(normal_min[v], reverse_min[v])) ans[v] = 'A';
    }

    std::cout << std::count(ans.begin(), ans.end(), 'A') << "\n"
              << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}