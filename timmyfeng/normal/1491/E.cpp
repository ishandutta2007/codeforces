#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int L = 32;

vector<int> adj[N], component;
int f[L], par[N], sub[N];

void dfs(int u) {
    sub[u] = 1;
    for (auto c : adj[u]) {
        if (c != par[u]) {
            par[c] = u;
            dfs(c);
            sub[u] += sub[c];
        }
    }
    component.push_back(u);
}

void erase(int u, int v) {
    for (int k = 0; k < 2; ++k) {
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        swap(u, v);
    }
}

void solve(int k, int u) {
    if (k <= 4) {
        return;
    }

    component.clear();
    par[u] = 0;
    dfs(u);

    array<int, 2> edge = {0, 0};
    for (auto v : component) {
        if (sub[v] == f[k - 2]) {
            edge = {par[v], v};
        } else if (sub[v] == f[k - 1]) {
            edge = {v, par[v]};
        }
    }

    if (edge == array<int, 2>{0, 0}) {
        cout << "NO\n";
        exit(0);
    }

    erase(edge[0], edge[1]);
    solve(k - 1, edge[0]);
    solve(k - 2, edge[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 0, f[1] = 1;
    for (int i = 0; i < L - 2; ++i) {
        f[i + 2] = f[i] + f[i + 1];
    }

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k = lower_bound(f, f + L, n) - f;
    if (f[k] != n) {
        cout << "NO\n";
        exit(0);
    }

    solve(k, 1);

    cout << "YES\n";
}