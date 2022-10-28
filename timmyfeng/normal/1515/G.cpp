#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

long long period[N], depth[N];
vector<array<int, 2>> adj[N];
vector<int> jda[N], order;
bool visited[N];
int color[N];

void dfs_order(int u) {
    color[u] = -1;
    for (auto [c, w] : adj[u]) {
        if (color[c] == 0) {
            dfs_order(c);
        }
    }
    order.push_back(u);
}

void dfs_color(int u, int x) {
    color[u] = x;
    for (auto c : jda[u]) {
        if (color[c] == -1) {
            dfs_color(c, x);
        }
    }
}

void dfs_calc(int u) {
    visited[u] = true;
    for (auto [c, w] : adj[u]) {
        if (color[u] == color[c]) {
            if (!visited[c]) {
                depth[c] = depth[u] + w;
                dfs_calc(c);
            } else {
                period[color[c]] = gcd(period[color[u]], abs(w + depth[u] - depth[c]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        jda[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            dfs_order(i);
        }
    }

    int k = 0;
    reverse(order.begin(), order.end());
    for (auto i : order) {
        if (color[i] == -1) {
            dfs_color(i, k++);
            dfs_calc(i);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        cout << (s % gcd(t, period[color[v]]) == 0 ? "YES" : "NO") << "\n";
    }
}