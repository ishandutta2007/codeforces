#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

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
    int m, n;
    std::cin >> m >> n;

    std::vector<lint> xs(m), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    std::vector<std::tuple<lint, int, int>> es;
    lint sum = 0;
    for (int i = 0; i < m; ++i) {
        int q;
        std::cin >> q;
        while (q--) {
            int j;
            std::cin >> j;
            --j;

            sum += xs[i] + ys[j];
            es.emplace_back(xs[i] + ys[j], i, j + m);
        }
    }

    std::sort(es.rbegin(), es.rend());

    UnionFind uf(n + m);
    for (auto [c, u, v] : es) {
        if (uf.same(u, v)) continue;
        sum -= c;
        uf.unite(u, v);
    }

    std::cout << sum << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}