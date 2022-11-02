#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

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
constexpr int N = 200000;

Graph<> graph;

std::vector<bool> visited;

int dfs(int v, int p, int g) {
    visited[v] = true;

    int ret = 1;
    for (auto e : graph[v]) {
        int u = e.dst;
        if (u == p || e.cost % g != 0) continue;
        ret += dfs(u, v, g);
    }

    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    std::vector<std::vector<int>> vss(N + 1);
    for (int v = 0; v < n; ++v) {
        std::cin >> xs[v];
        vss[xs[v]].push_back(v);
    }

    graph.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph.span(false, u, v, std::gcd(xs[u], xs[v]));
    }

    visited.resize(n, false);
    std::vector<lint> ans(N + 1, 0);

    for (int g = 1; g <= N; ++g) {
        std::vector<int> vs;
        for (int x = g; x <= N; x += g) {
            std::copy(vss[x].begin(), vss[x].end(), std::back_inserter(vs));
        }

        for (auto v : vs) {
            if (visited[v]) continue;
            lint sz = dfs(v, -1, g);
            ans[g] += sz * (sz + 1) / 2;
        }

        for (auto v : vs) visited[v] = false;
    }

    for (int g = N; g >= 1; --g) {
        for (int x = g * 2; x <= N; x += g) {
            ans[g] -= ans[x];
        }
    }

    for (int g = 1; g <= N; ++g) {
        if (ans[g] != 0) std::cout << g << " " << ans[g] << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}