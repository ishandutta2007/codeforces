#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <cassert>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;

    Edge() = default;
    Edge(int src, int dst, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }
};

template <class Cost = int>
struct Graph : public std::vector<std::vector<Edge<Cost>>> {
    Graph(int n = 0) : std::vector<std::vector<Edge<Cost>>>(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        (*this)[src].emplace_back(src, dst, cost);
        if (!direct) (*this)[dst].emplace_back(dst, src, cost);
    }
};

struct UnionFind {
    std::vector<int> par;
    int gnum;

    explicit UnionFind(int n) : par(n, -1), gnum(n) {}

    int find(int v) {
        return (par[v] < 0) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (par[u] > par[v]) std::swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return par[v] < 0; }
    int size(int v) { return -par[find(v)]; }
};

using lint = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> cs(n);
    std::vector<std::vector<int>> cvs(k);
    for (int v = 0; v < n; ++v) {
        auto& c = cs[v];
        std::cin >> c;
        cvs[--c].push_back(v);
    }

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, --u, --v);
    }

    UnionFind uf(n);
    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            int u = e.dst;
            if (cs[u] == cs[v]) uf.unite(u, v);
        }
    }

    std::vector<int> cols(n, -1);
    std::vector<bool> valid(k, true);
    {
        auto dfs = [&](auto&& f, int v) -> void {
            for (auto e : graph[v]) {
                int u = e.dst;
                if (cs[u] != cs[v]) continue;

                if (cols[u] == -1) {
                    cols[u] = 1 - cols[v];
                    f(f, u);
                } else if (cols[u] == cols[v]) {
                    valid[cs[v]] = false;
                }
            }
        };

        for (int v = 0; v < n; ++v) {
            if (uf.ispar(v)) {
                cols[v] = 0;
                dfs(dfs, v);
            }
        }
    }

    std::vector<int> leader(n);
    for (int v = 0; v < n; ++v) leader[v] = uf.find(v);

    std::vector<std::map<int, std::vector<std::pair<int, int>>>> ess(k);
    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            int u = e.dst;
            if (cs[u] < cs[v]) ess[cs[u]][cs[v]].emplace_back(u, v);
        }
    }

    std::set<std::pair<int, int>> outs;

    uf = UnionFind(n * 2);  // v, v+n
    std::vector<int> changed;
    for (int c = 0; c < k; ++c) {
        for (const auto& [nc, es] : ess[c]) {
            for (auto [u, v] : es) {
                int t = (cols[u] == cols[v]);
                uf.unite(leader[u] + 0, leader[v] + t * n);
                uf.unite(leader[u] + n, leader[v] + (1 - t) * n);

                changed.push_back(leader[u]);
                changed.push_back(leader[v]);
            }

            for (auto p : changed) {
                if (uf.same(p, p + n)) {
                    outs.emplace(c, nc);
                    break;
                }
            }

            // reset
            for (auto p : changed) {
                uf.par[p] = uf.par[p + n] = -1;
            }
            changed.clear();
        }
    }

    lint c = std::accumulate(valid.begin(), valid.end(), 0LL);
    lint ans = c * (c - 1) / 2;

    for (auto [u, v] : outs) {
        if (valid[u] && valid[v]) --ans;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}