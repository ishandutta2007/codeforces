#include <vector>
#include <utility>
#include <iostream>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
    }
    std::vector<std::vector<int>> check(n);
    std::vector<std::vector<int>> adj(n);
    {
        std::vector<int> used(n);
        std::vector<int> stack;
        for (int i = 0; i < n; ++i) {
            if (deg[i] < k) {
                stack.push_back(i);
            }
        }
        while (!stack.empty()) {
            int v = stack.back();
            stack.pop_back();
            used[v] = true;
            if (deg[v] == k - 1) {
                for (int u: g[v]) {
                    if (!used[u]) {
                        adj[v].push_back(u);
                        check[u].push_back(v);
                    }
                }
            }
            for (int u: g[v]) {
                --deg[u];
                if (deg[u] == k - 1) {
                    stack.push_back(u);
                }
            }
        }
        std::vector<int> surv;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                surv.push_back(i);
            }
        }
        if (!surv.empty()) {
            std::cout << "1 " << surv.size() << '\n';
            for (int i = 0; i < surv.size(); ++i) {
                std::cout << surv[i] + 1 << " \n"[i + 1 == surv.size()];
            }
            return;
        }
    }

    std::vector<int> ans(n, 1);
    std::vector<int> a(n);
    for (int v = 0; v < n; ++v) {
        for (int u: g[v]) {
            a[u] = 1;
        }
        a[v] = 1;
        for (int u: check[v]) {
            for (int e: adj[u]) {
                if (!a[e]) {
                    ans[u] = 0;
                }
            }
        }
        a[v] = 0;
        for (int u: g[v]) {
            a[u] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (adj[i].size() != k - 1) {
            continue;
        }
        if (ans[i]) {
            std::cout << "2\n";
            std::cout << i + 1;
            for (int v: adj[i]) {
                std::cout << ' ' << v + 1;
            }
            std::cout << '\n';
            return;
        }
    }
    std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}