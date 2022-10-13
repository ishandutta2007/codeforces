#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> tab;
vector<int> d;
vector<int> flow;
vector<bool> vis;

int lca(int u, int v) {
    if (d[u] < d[v]) { swap(u, v); }
    for (int i = 19; i >= 0; i--) {
        if (d[u] - (1 << i) >= d[v]) {
            u = tab[u][i];
        }
    }
    if (u == v) { return u; }
    for (int i = 19; i >= 0; i--) {
        if (tab[u][i] != tab[v][i]) {
            u = tab[u][i];
            v = tab[v][i];
        }
    }
    return tab[v][0];
}

void dfs(int curr, int par) {
    vis[curr] = true;
    if (par != -1) { tab[curr][0] = par; }
    for (int i = 1; i < 20; i++) {
        tab[curr][i] = tab[ tab[curr][i - 1] ][i - 1];
    }
    for (int next : adj[curr]) {
        if (!vis[next]) {
            d[next] = d[curr] + 1;
            dfs(next, curr);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    tab.resize(n, vector<int>(20));
    d.resize(n);
    flow.resize(n);
    vis.resize(n, false);
    dfs(0, -1);
    int q; cin >> q;
    vector<vector<int>> ans(q);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        ++flow[a], ++flow[b];
        int l = lca(a, b);
        vector<int> x;
        while (a != l) {
            x.push_back(a);
            a = tab[a][0];
        }
        vector<int> y;
        while (b != l) {
            y.push_back(b);
            b = tab[b][0];
        }
        reverse(y.begin(), y.end());
        x.push_back(l);
        x.insert(x.end(), y.begin(), y.end());
        ans[i] = x;
    }
    int extra = 0;
    for (int i = 0; i < n; i++) {
        extra += flow[i] % 2;
    }
    if (extra == 0) {
        cout << "YES" << "\n";
        for (vector<int> path : ans) {
            cout << path.size() << "\n";
            for (int x : path) {
                cout << x + 1 << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO" << "\n";
        cout << extra / 2 << "\n";
    }
}