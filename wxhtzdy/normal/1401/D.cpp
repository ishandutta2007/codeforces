#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int64_t> c;
        std::vector<int> sz(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            sz[u] = 1;
            for (int v : e[u]) {
                if (v == p)
                    continue;
                dfs(v, u);
                sz[u] += sz[v];
                c.push_back(sz[v] * 1LL * (n - sz[v]));
            }
        };
        dfs(0, 0);
        //std::cout << c.size() << "\n";
        std::sort(c.begin(), c.end());
        int m;
        std::cin >> m;
        std::vector<int> a(m);
        for (int i = 0; i < m; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        if (m <= n - 1) {
            int64_t ans = 0;
            std::reverse(a.begin(), a.end());
            std::reverse(c.begin(), c.end());
            for (int i = 0; i < m; ++i)
                ans = (ans + (c[i] * 1LL * a[i]) % P) % P;
            for (int i = m; i < n - 1; ++i)
                ans = (ans + c[i]) % P;
            std::cout << ans << "\n";
        } else {
            int64_t ans = 0;
            for (int i = 0; i < n - 2; ++i)
                ans = (ans + a[i] * 1LL * c[i] % P) % P;
            int64_t p = 1;
            for (int i = n - 2; i < m; ++i)
                p = (p * a[i]) % P;
            ans = (ans + (p * c[n - 2] % P) % P) % P;
            std::cout << ans << "\n";
        }
    }
    return 0;
}