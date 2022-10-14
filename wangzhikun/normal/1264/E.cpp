#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> d(n);
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> f(n, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        d[u]++;
        g[u][v] = 1, g[v][u] = 2;
        f[u][v] = f[v][u] = 0;
    }
    priority_queue<pair<int, int>> heap;
    for (int i = 0; i < n; i++) {
        if (d[i] < n - 1) {
            heap.push({-d[i], i});
        }
    }
    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
        queue<int> que;
        vector<int> vis(n), from(n);
        que.push(u), vis[u] = 1;
        int id = -1;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int found = 0;
            for (int w = 0; w < n; w++) if (w != v && !g[v][w]) {
                found = 1;
                break;
            }
            if (found) {
                id = v;
                break;
            }
            for (int w = 0; w < n; w++) if (!vis[w] && g[v][w] == 2 && f[v][w] == 1) {
                que.push(w), vis[w] = 1;
                from[w] = v;
            }
        }
        if (id == -1) {
            continue;
        }
        for (int v = 0; v < n; v++) if (v != id && !g[id][v]) {
            g[id][v] = 1, g[v][id] = 2;
            break;
        }
        while (id != u) {
            int nid = from[id];
            swap(g[id][nid], g[nid][id]);
            id = nid;
        }
        d[u]++;
        if (d[u] < n - 1) {
            heap.push({-d[u], u});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0;
            }
            else {
                cout << 2 - g[i][j];
            }
        }
        cout << "\n";
    }
    return 0;
}