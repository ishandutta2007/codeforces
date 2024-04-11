#include <bits/stdc++.h>
struct DSU {
    std::vector<int> p, rk;
    DSU(int N) : p(N), rk(N) {
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rk[u] < rk[v]) {
            std::swap(u, v);
        }
        p[v] = u, rk[u] += (rk[u] == rk[v]);
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    int Q;
    std::cin >> Q;
    a.resize(N + Q);
    std::vector<int> id(N + Q);
    DSU dsu(N + Q);
    std::map<int, int> c;
    auto create = [&](int i) {
        if (c.count(a[i])) {
            dsu.unite(c[a[i]], i);
        } else {
            c[a[i]] = i;
        }
    };
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        create(i);
    }
    for (int q = 0; q < Q; ++q) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int p, x;
            std::cin >> p >> x;
            --p;
            int i = id[p] = N + q;
            a[i] = x;
            create(i);
        } else {
            int x;
            std::cin >> x;
            int u = N + q;
            a[u] = x;
            create(u);
            while (c.begin()->first < x) {
                int v = dsu.find(c.begin()->second);
                a[v] = x;
                dsu.unite(v, u);
                c.erase(c.begin());
            }
        }
    }
    for (int u = 0; u < N; ++u) {
        std::cout << a[dsu.find(id[u])] << "\n "[u + 1 < N];
    }
    exit(0);
}