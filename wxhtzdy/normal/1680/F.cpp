#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n, std::vector<int>());
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    std::vector<int> dep(n);
    std::vector<int> col(n);
    std::vector<bool> vis(n);
    std::vector<std::pair<int, int>> bck;
    std::function<void(int, int)> dfs = [&](int u, int par) {
        dep[u] = dep[par] + 1;
        col[u] = col[par] ^ 1;
        vis[u] = true;
        //std::cout << u + 1 << " " << par + 1 << "\n";
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, u);
            } else {
                if (v != par && dep[u] < dep[v]) {
                    bck.push_back({u, v});
                    //std::cout << "omg " << u + 1 << " " << v + 1 << "\n";
                }
            }
        }
    };
    dfs(0, 0);

    int cnt = 0;
    for (auto& e : edges) {
        if (col[e.first] == col[e.second])
            cnt++;
        if (cnt == 1 && col[e.first] == 0 && col[e.second] == 0)
            for (int i = 0; i < n; i++)
                col[i] ^= 1;
    }

    if (cnt <= 1) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            std::cout << col[i];
        }
        std::cout << "\n";
        return;
    }

    std::vector<int> cntBad(n);
    std::vector<int> cntGood(n);
    std::function<void(int, int)> badPath = [&](int u, int v) {
        if (dep[u] < dep[v])
            std::swap(u, v);
        //std::cout << "badPath " << u + 1 << " " << v + 1 << "\n";
        cntBad[u] += 1;
        cntBad[v] -= 1;
    };
    
    std::function<void(int, int)> goodPath = [&](int u, int v) {
        if (dep[u] < dep[v])
            std::swap(u, v);
        //std::cout << "goodPath " << u + 1 << " " << v + 1 << "\n";
        cntGood[u] += 1;
        cntGood[v] -= 1;
    };

    for (auto& e : bck) {
        if (col[e.first] == col[e.second]) {
            badPath(e.first, e.second);
        } else {
            goodPath(e.first, e.second);
        }
    }

    fill(vis.begin(), vis.end(), false);
    std::function<void(int)> calc = [&](int u) {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                calc(v);
                cntBad[u] += cntBad[v];
                cntGood[u] += cntGood[v];
            }
        }
    };
    calc(0);

    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (cntGood[i] == 0 && cntBad[i] == cnt) {
            idx = i;
        }
    }

    if (idx == -1) {
        std::cout << "NO\n";
        return;
    }
    
    for (int i = 0; i < n; i++) g[i].clear();

    for (auto& e : edges) {
        if (dep[e.first] > dep[e.second])
            std::swap(e.first, e.second);
        if (e.second != idx) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
    }

    fill(vis.begin(), vis.end(), false);
    dfs(0, 0);

    cnt = 0;
    for (auto& e : edges) {
        if (col[e.first] == col[e.second])
            cnt++;
        if (cnt == 1 && col[e.first] == 0 && col[e.second] == 0)
            for (int i = 0; i < n; i++)
                col[i] ^= 1;
    }

    if (cnt <= 1) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            std::cout << col[i];
        }
        std::cout << "\n";
        return;
    }

    std::cout << "NO\n";
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}