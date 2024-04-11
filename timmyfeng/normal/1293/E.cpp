#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj, p, sz;
vector<vector<long long>> memo;

void dfs(int rt, int u) {
    sz[rt][u] = 1;
    for (int i : adj[u]) {
        if (i == p[rt][u]) continue;
        p[rt][i] = u;
        dfs(rt, i);
        sz[rt][u] += sz[rt][i];
    }
}

long long max_s(int u, int v) {
    if (u == v) return 0;
    if (memo[u][v] == -1) {
        memo[u][v] = sz[u][v] * sz[v][u] + max(max_s(p[v][u], v), max_s(u, p[u][v]));
    }
    return memo[u][v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sz.assign(n, vector<int>(n, -1));
    p.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        dfs(i, i);
    }

    memo.assign(n, vector<long long>(n, -1));
    long long sol = 0;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            sol = max(sol, max_s(u, v));
        }
    }
    cout << sol << "\n";
}