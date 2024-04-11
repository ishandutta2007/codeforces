#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

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

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    Graph<> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    std::vector<int> score(n);
    std::function<int(int, int, int)> dfs =
        [&](int v, int p, int d) -> int {
        int sz = 0;

        for (auto e : graph[v]) {
            int u = e.dst;
            if (u == p) continue;
            sz += dfs(u, v, d + 1);
        }

        score[v] = d - sz;
        return sz + 1;
    };
    dfs(0, -1, 0);

    std::sort(score.rbegin(), score.rend());
    std::cout << std::accumulate(score.begin(), score.begin() + k, 0LL) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}