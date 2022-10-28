#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

bool ans[N], black[N], special[N];
vector<int> adj[N];
int sub[N], goals;

bool reachable(int u) {
    return special[u] && sub[u] >= 2;
}

void dfs_pull(int u, int p = -1) {
    sub[u] = black[u];
    for (auto c : adj[u]) {
        if (c != p) {
            dfs_pull(c, u);
            sub[u] += sub[c];
        }
    }
    goals += reachable(u);
}

void dfs_push(int u, int p = -1) {
    for (auto c : adj[u]) {
        if (c != p) {
            goals -= reachable(u) + reachable(c);
            sub[u] -= sub[c], sub[c] += sub[u];
            goals += reachable(u) + reachable(c);

            dfs_push(c, u);

            goals -= reachable(u) + reachable(c);
            sub[c] -= sub[u], sub[u] += sub[c];
            goals += reachable(u) + reachable(c);
        }
    }
    ans[u] = goals > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> black[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (black[i]) {
            special[i] = true;
            for (auto j : adj[i]) {
                special[j] = true;
            }
        }
    }

    dfs_pull(0);
    dfs_push(0);

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";
}