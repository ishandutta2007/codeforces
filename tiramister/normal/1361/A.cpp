#include <iostream>
#include <vector>
#include <set>

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

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    std::vector<std::vector<int>> vss(n);
    for (int v = 0; v < n; ++v) {
        int t;
        std::cin >> t;
        vss[--t].push_back(v);
    }

    std::vector<int> ans;
    std::vector<int> xs(n, -1);
    for (int t = 0; t < n; ++t) {
        for (auto& v : vss[t]) {
            std::set<int> s;
            for (auto e : graph[v]) {
                s.insert(xs[e.dst]);
            }

            int p = 0;
            while (s.count(p)) ++p;
            if (p != t) {
                std::cout << -1 << "\n";
                return;
            }

            ans.push_back(v);
            xs[v] = p;
        }
    }

    for (auto v : ans) {
        std::cout << v + 1 << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}