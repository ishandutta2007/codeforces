#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

vector<int> adj[MX + 1];
bool a[MX + 1];
int dpDown[MX + 1], dpUp[MX + 1];

void dfs1(int u, int p = 0) {
    dpDown[u] = (a[u] ? 1 : -1);
    for (auto c : adj[u]) {
        if (c != p) {
            dfs1(c, u);
            if (dpDown[c] > 0) {
                dpDown[u] += dpDown[c];
            }
        }
    }
}

void dfs2(int u, int p = 0) {
    dpUp[u] = dpUp[p] + dpDown[p];
    if (dpDown[u] > 0) {
        dpUp[u] -= dpDown[u];
    }
    dpUp[u] = max(0, dpUp[u]);
    for (auto c : adj[u]) {
        if (c != p) {
            dfs2(c, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= n; ++i) {
        cout << dpDown[i] + dpUp[i] << ' ';
    }
}