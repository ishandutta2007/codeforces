#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
struct DSU {
    std::vector<int> p, rk;
    int c = 0;
    DSU(int N) : p(N), rk(N), c(N) {
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rk[u] < rk[v]) std::swap(u, v);
        p[v] = u;
        rk[u] += rk[u] == rk[v];
        --c;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> a(N);
    for (int u = 0; u < N; ++u) {
        a[u].resize(N);
        for (int v = 0; v < N; ++v) {
            std::cin >> a[u][v];
        }
    }
    DSU dsu(N);
    std::vector<int> label(N);
    std::iota(label.begin(), label.end(), 0);
    int K = N;
    std::vector<int> s(K), c(K);
    for (int u = 0; u < K; ++u) {
        c[u] = a[u][u];
    }
    while (dsu.c > 1) {
        int e = -1, best = std::numeric_limits<int>::max();
        for (int u = 0; u < N; ++u) {
            int mn = std::numeric_limits<int>::max();
            for (int v = 0; v < N; ++v) {
                if (dsu.find(u) != dsu.find(v)) {
                    mn = std::min(mn, a[u][v]);
                }
            }
            if (mn < best) {
                e = u;
                best = mn;
            }
        }
        s[label[dsu.find(e)]] = K;
        for (int v = 0; v < N; ++v) {
            if (dsu.find(e) != dsu.find(v) && a[e][v] == best) {
                s[label[dsu.find(v)]] = K;
                dsu.unite(e, v);
            }
        }
        s.push_back(0);
        c.push_back(best);
        label[dsu.find(e)] = K++;
    }
    std::cout << K << '\n';
    for (int j = 0; j < K; ++j) {
        std::cout << c[j] << "\n "[j + 1 < K];
    }
    std::cout << K << '\n';
    for (int j = 0; j < K - 1; ++j) {
        std::cout << j + 1 << ' ' << s[j] + 1 << '\n';
    }
    return 0;
}