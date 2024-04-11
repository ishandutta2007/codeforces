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

struct UnionFind {
    std::vector<int> par, sz;
    int gnum;

    explicit UnionFind(int n)
        : par(n), sz(n, 1), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return (par[v] == v) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) std::swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    Graph<> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    lint ans = 0;

    std::vector<int> vs(n);
    std::iota(vs.begin(), vs.end(), 0);

    for (int q = 0; q < 2; ++q) {
        std::sort(vs.begin(), vs.end(),
                  [&](int u, int v) { return xs[u] < xs[v]; });

        UnionFind uf(n);
        std::vector<bool> visited(n, false);

        for (auto v : vs) {
            visited[v] = true;

            lint c2sum = 0;
            for (auto e : graph[v]) {
                int u = e.dst;
                if (!visited[u]) continue;

                lint sz = uf.size(u);
                c2sum += sz * sz;

                uf.unite(u, v);
            }

            lint sz = uf.size(v);
            ans += (sz * sz - c2sum) * xs[v];
        }

        for (auto& x : xs) x = -x;
    }

    std::cout << ans / 2 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}