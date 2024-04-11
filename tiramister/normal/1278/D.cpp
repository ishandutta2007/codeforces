#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

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

void fail() {
    std::cout << "NO" << std::endl;
    std::exit(0);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> segs(n);
    for (auto& s : segs) {
        std::cin >> s.first >> s.second;
        --s.first, --s.second;
    }
    std::sort(segs.begin(), segs.end());

    int m = 0;
    UnionFind uf(n);

    std::set<std::pair<int, int>> rs;
    for (int u = 0; u < n; ++u) {
        auto seg = segs[u];
        while (!rs.empty() && rs.begin()->first < seg.first) {
            rs.erase(rs.begin());
        }

        for (auto r : rs) {
            if (seg.second < r.first) break;
            int v = r.second;

            uf.unite(u, v);
            if (++m >= n) fail();
        }
        rs.emplace(seg.second, u);
    }

    if (m != n - 1) fail();

    for (int v = 0; v < n; ++v) {
        if (!uf.same(0, v)) fail();
    }

    std::cout << "YES" << std::endl;
    return 0;
}