#include <iostream>
#include <algorithm>
#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst, id;
    bool valid;
    Cost cost;

    Edge(int src = -1, int dst = -1, int id = -1, Cost cost = 1)
        : src(src), dst(dst), id(id), valid(true), cost(cost){};

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
    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, --u, --v, i);
    }

    std::vector<int> ids;
    std::vector<int> status(n, -1);
    auto dfs = [&](auto&& f, int v) -> bool {
        status[v] = 1;

        for (auto e : graph[v]) {
            if (!e.valid) continue;

            int u = e.dst;

            if (status[u] == 0) continue;
            if (status[u] == 1) {
                ids.push_back(e.id);
                return true;
            }

            if (f(f, u)) {
                ids.push_back(e.id);
                return true;
            }
        }

        status[v] = 0;
        return false;
    };

    auto detect = [&]() {
        std::fill(status.begin(), status.end(), -1);
        ids.clear();

        for (int v = 0; v < n; ++v) {
            if (status[v] == -1) dfs(dfs, v);
            if (!ids.empty()) return;
        }
    };

    detect();
    if (ids.empty()) {
        std::cout << "YES\n";
        return;
    }

    auto cids = ids;
    for (auto id : cids) {
        for (int v = 0; v < n; ++v) {
            for (auto& e : graph[v]) {
                if (e.id == id) e.valid = false;
            }
        }

        detect();
        if (ids.empty()) {
            std::cout << "YES\n";
            return;
        }

        for (int v = 0; v < n; ++v) {
            for (auto& e : graph[v]) {
                if (e.id == id) e.valid = true;
            }
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}