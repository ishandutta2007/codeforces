#include <iostream>
#include <vector>
#include <functional>

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
        if (!direct) graph[dst].emplace_back(dst, src, id, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int m;
    std::cin >> m;

    Graph<int> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph.span(true, u, v, i, -1);
        graph.span(true, v, u, i, 1);
    }

    std::vector<int> weight(m, 0);

    std::vector<bool> visited(n, false);
    std::function<void(int, int)> dfs =
        [&](int v, int p) -> void {
        visited[v] = true;

        for (auto e : graph[v]) {
            int u = e.dst;
            if (u == p || visited[u]) continue;
            dfs(u, v);
            xs[v] -= weight[e.id] * e.cost;
        }

        for (auto e : graph[v]) {
            int u = e.dst;
            if (u != p) continue;
            weight[e.id] = xs[v] * e.cost;
            xs[v] = 0;
        }
    };

    dfs(0, -1);
    if (xs[0] != 0) {
        std::cout << "Impossible\n";
    } else {
        std::cout << "Possible\n";
        for (auto w : weight) {
            std::cout << w << "\n";
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}