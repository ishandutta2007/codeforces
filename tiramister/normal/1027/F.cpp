#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

struct UnionFind {
    std::vector<int> par, sz;

    explicit UnionFind(int n)
        : par(n), sz(n, 1) {
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
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs;
    std::vector<std::pair<int, int>> ps(n);
    for (auto& p : ps) {
        std::cin >> p.first >> p.second;
        xs.push_back(p.first);
        xs.push_back(p.second);
    }

    auto revx = compress(xs);

    int lmax = 0;
    for (auto& p : ps) {
        p.first = revx[p.first];
        p.second = revx[p.second];
        lmax = std::max(lmax, p.first);
    }

    int m = xs.size();
    int ok = m + 1, ng = lmax;
    while (ok - ng > 1) {
        int dnum = (ok + ng) / 2;

        bool judge = true;

        UnionFind uf(dnum);
        for (auto p : ps) {
            if (p.second < dnum) {
                uf.unite(p.first, p.second);
            }
        }

        std::vector<int> esz(dnum, 0);
        for (auto p : ps) {
            ++esz[uf.find(p.first)];
        }

        for (int v = 0; v < dnum; ++v) {
            if (esz[v] > uf.size(v)) judge = false;
        }

        if (judge) {
            ok = dnum;
        } else {
            ng = dnum;
        }
    }

    std::cout << (ok > m ? -1 : xs[ok - 1]) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}