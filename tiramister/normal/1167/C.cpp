#include <iostream>
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

int main() {
    int n, m;
    std::cin >> n >> m;

    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;

        std::vector<int> g(k);
        for (auto& x : g) {
            std::cin >> x;
            --x;
        }

        for (int j = 0; j + 1 < k; ++j) {
            uf.unite(g[j], g[j + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << uf.size(i) << ' ';
    }
    std::cout << std::endl;
    return 0;
}