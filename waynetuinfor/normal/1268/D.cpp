#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) adj[i][j] = s[j] - '0';
    }
    if (n <= 6) {
        int ans1 = n + 1, ans2 = 0;
        vector<int> fc(n + 1, 1);
        for (int i = 1; i <= n; ++i) fc[i] = fc[i - 1] * i;
        for (int s = 0; s < (1 << n); ++s) {
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1) {
                    for (int j = 0; j < n; ++j) {
                        if (i != j) adj[i][j] ^= 1, adj[j][i] ^= 1;
                    }
                }
            }
            vector<int> od(n);
            iota(od.begin(), od.end(), 0);
            bool hp = false;
            do {
                bool ok = true;
                for (int i = 0; i < n; ++i) ok &= adj[od[i]][od[(i + 1) % n]];
                if (ok) {
                    hp = true;
                    break;
                }
            } while (next_permutation(od.begin(), od.end()));
            if (hp) {
                int pc = __builtin_popcount(s);
                if (pc < ans1) {
                    ans1 = pc;
                    ans2 = fc[pc];
                } else if (pc == ans1) {
                    ans2 += fc[pc];
                }
            }
            for (int i = 0; i < n; ++i) {
                if (s >> i & 1) {
                    for (int j = 0; j < n; ++j) {
                        if (i != j) adj[i][j] ^= 1, adj[j][i] ^= 1;
                    }
                }
            }
        }
        if (ans1 > n) cout << -1 << endl;
        else cout << ans1 << ' ' << ans2 << endl;
        return 0;
    }

    constexpr int kN = 2000;
    vector<bitset<kN>> g(n), r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j]) {
                g[i].set(j);
                r[j].set(i);
            }
        }
    }
    auto Check = [&]() {
        bitset<kN> vis;
        vector<int> ord;

        function<void(int)> Dfs = [&](int x) {
            vis.set(x);
            while (true) {
                auto cd = ((~vis) & (g[x]));
                int u = cd._Find_first();
                if (u >= n) break;
                Dfs(u);
            }
            ord.push_back(x);
        };

        function<void(int)> RevDfs = [&](int x) {
            vis.set(x);
            while (true) {
                auto cd = ((~vis) & (r[x]));
                int u = cd._Find_first();
                if (u >= n) break;
                RevDfs(u);
            }
        };

        for (int i = 0; i < n; ++i) if (!vis[i]) Dfs(i);
        vis.reset();
        RevDfs(ord[n - 1]);
        return vis.count() == n;
    };

    auto Flip = [&](int v) {
        for (int i = 0; i < n; ++i) {
            if (adj[i][v]) {
                g[i].flip(v);
                g[v].flip(i);
                r[v].flip(i);
                r[i].flip(v);
            }
            if (adj[v][i]) {
                g[i].flip(v);
                g[v].flip(i);
                r[v].flip(i);
                r[i].flip(v);
            }
        }
        bool res = Check();
        for (int i = 0; i < n; ++i) {
            if (adj[i][v]) {
                g[i].flip(v);
                g[v].flip(i);
                r[v].flip(i);
                r[i].flip(v);
            }
            if (adj[v][i]) {
                g[i].flip(v);
                g[v].flip(i);
                r[v].flip(i);
                r[i].flip(v);
            }
        }
        return res;
    };

    if (Check()) {
        cout << 0 << ' ' << 1 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res += Flip(i);
    cout << 1 << ' ' << res << endl;
    return 0;
}