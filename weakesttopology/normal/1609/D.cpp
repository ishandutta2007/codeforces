#include <bits/stdc++.h>
struct DSU {
    std::vector<int> p, rk, sz;
    DSU(int N) : p(N), rk(N), sz(N, 1) {
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
        sz[u] += sz[v];
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, D;
    std::cin >> N >> D;
    DSU dsu(N);
    for (int i = 0; i < D; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        dsu.unite(x, y);
        std::vector<int> freq(N + 1);
        int C = 0;
        for (int u = 0; u < N; ++u) {
            if (dsu.find(u) == u) {
                ++freq[dsu.sz[u]];
                ++C;
            }
        }
        int rem = i + 1 - (N - C) + 1;
        int ans = -1;
        for (int sz = N; sz >= 1; --sz) {
            int take = std::min(rem, freq[sz]);
            rem -= take;
            ans += take * sz;
        }
        std::cout << ans << '\n';
    }
    exit(0);
}