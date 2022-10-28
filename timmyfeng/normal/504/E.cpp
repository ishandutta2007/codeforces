#include <bits/stdc++.h>
using namespace std;

const int K = 2000000, N = 300001, L = __lg(N) + 1;
const long long M = 1000000007, B = 37;

long long base[N], inv[N];

vector<int> adj[N];
string letter;

vector<int> head[N], tail[N];
long long up[N], down[N];
int depth[N], dsu[N];

int low[K], high[K], mid[K], code[K];
int s[K], t[K], l[K], a[K], b[K];
int path[N];

int find(int u) {
    if (dsu[u] == 0) {
        return u;
    } else {
        dsu[u] = find(dsu[u]);
        return dsu[u];
    }
}

void dfs_lca(int u, int p = 0) {
    int x = letter[u - 1] - 'a';
    down[u] = (down[p] + base[depth[u]] * x) % M;
    up[u] = (B * up[p] + x) % M;

    for (auto i : head[u]) {
        l[i] = find(t[i]);
    }

    for (auto i : tail[u]) {
        l[i] = find(s[i]);
    }

    for (auto c : adj[u]) {
        if (c != p) {
            depth[c] = depth[u] + 1;
            dfs_lca(c, u);
            dsu[c] = u;
        }
    }
}

void dfs_calc(int u, int p = 0) {
    path[depth[u]] = u;

    for (auto i : head[u]) {
        if (low[i / 2] != high[i / 2]) {
            int mid = (low[i / 2] + high[i / 2] + 1) / 2;
            int len = min(a[i], mid);
            int v = path[depth[u] - len];
            code[i] = (code[i] + up[u] - up[v] * base[len]) % M;
        }
    }

    for (auto i : tail[u]) {
        if (low[i / 2] != high[i / 2]) {
            int mid = (low[i / 2] + high[i / 2] + 1) / 2;
            int len = mid - a[i];
            if (len > 0) {
                int v = path[depth[l[i]] + len - 1];
                int w = path[depth[l[i]] - 1];
                code[i] = (code[i] + (down[v] - down[w]) * b[i]) % M;
            }
        }
    }

    for (auto c : adj[u]) {
        if (c != p) {
            dfs_calc(c, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    base[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        base[i] = B * base[i - 1] % M;
        inv[i] = 621621626LL * inv[i - 1] % M;
    }

    int n;
    cin >> n >> letter;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m;
    cin >> m;

    for (int i = 0; i < 2 * m; ++i) {
        cin >> s[i] >> t[i];
        head[s[i]].push_back(i);
        tail[t[i]].push_back(i);
    }

    dfs_lca(1);

    fill(high, high + m, n);
    for (int i = 0; i < 2 * m; ++i) {
        high[i / 2] = min(high[i / 2], depth[s[i]] + depth[t[i]] - 2 * depth[l[i]] + 1);
        a[i] = depth[s[i]] - depth[l[i]];
        int x = a[i] - depth[l[i]];
        b[i] = x > 0 ? base[x] : inv[-x];
    }

    while (!equal(low, low + m, high)) {
        fill(code, code + 2 * m, 0);

        dfs_calc(1);

        for (int i = 0; i < m; ++i) {
            int mid = (low[i] + high[i] + 1) / 2;
            if ((code[2 * i] + M) % M == (code[2 * i + 1] + M) % M) {
                low[i] = mid;
            } else {
                high[i] = mid - 1;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << high[i] << "\n";
    }
}