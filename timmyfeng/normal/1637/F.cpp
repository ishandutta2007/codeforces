#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

vector<int> max_h[N], adj[N];
long long ans, cost;
int h[N];

void dfs_root(int u, int p = 0) {
    for (auto c : adj[u]) {
        if (c != p) {
            dfs_root(c, u);
            max_h[u].push_back(max(h[c], max_h[c][0]));
        }
    }

    while (ssize(max_h[u]) < 2) max_h[u].push_back(0);
    ranges::sort(max_h[u], greater<int>());

    cost += max(0, h[u] - max_h[u][0]);
}

void dfs_reroot(int u, int p = 0) {
    cost -= max(0, h[u] - max_h[u][0]);
    if (p != 0) max_h[u].push_back(max(h[p], max_h[p][0]));
    ranges::sort(max_h[u], greater<int>());
    cost += max(0, h[u] - max_h[u][0]);

    ans = min(ans, cost);

    for (auto c : adj[u]) {
        if (c != p) {
            cost -= max(0, h[u] - max_h[u][0]);
            if (max(h[c], max_h[c][0]) == max_h[u][0]) swap(max_h[u][0], max_h[u][1]);
            cost += max(0, h[u] - max_h[u][0]);

            dfs_reroot(c, u);

            cost -= max(0, h[u] - max_h[u][0]);
            if (max_h[u][0] < max_h[u][1]) swap(max_h[u][1], max_h[u][0]);
            cost += max(0, h[u] - max_h[u][0]);
        }
    }

    cost -= max(0, h[u] - max_h[u][0]);
    if (p != 0) max_h[u].erase(ranges::find(max_h[u], max(h[p], max_h[p][0])));
    cost += max(0, h[u] - max_h[u][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 1; i <= n; ++i) cin >> h[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cost = *max_element(h + 1, h + n + 1);
    ans = LLONG_MAX;

    dfs_root(1);
    dfs_reroot(1);

    cout << ans << "\n";
}