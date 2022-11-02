#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

struct UnionFind {
    std::vector<int> par;
    int gnum;

    explicit UnionFind(int n)
        : par(n), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return (par[v] == v) ? v : (par[v] = find(par[v]));
    }

    // v -> u
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> ids(n);
    std::vector<std::vector<int>> dss(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> ids[i];
        --ids[i];
        dss[ids[i]].push_back(i);
    }

    int score = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (ids[i] != ids[i + 1]) ++score;
    }
    std::cout << score << "\n";

    UnionFind uf(m);

    for (int q = 0; q < m - 1; ++q) {
        int x, y;
        std::cin >> x >> y;
        x = uf.find(--x);
        y = uf.find(--y);

        if (dss[x].size() < dss[y].size()) std::swap(x, y);

        // y -> x
        for (auto i : dss[y]) {
            if (i - 1 >= 0 && ids[i - 1] == ids[i]) ++score;
            if (i + 1 < n && ids[i + 1] == ids[i]) ++score;

            ids[i] = x;

            if (i - 1 >= 0 && ids[i - 1] == ids[i]) --score;
            if (i + 1 < n && ids[i + 1] == ids[i]) --score;

            dss[x].push_back(i);
        }

        dss[y].clear();
        dss[y].shrink_to_fit();
        uf.unite(x, y);

        std::cout << score << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}