#include <bits/stdc++.h>
using namespace std;

const int N = 300001;

int grundy[N], par[N];
vector<int> adj[N];
bool ground[N];

void dfs(int u) {
    for (auto c : adj[u]) {
        adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
        par[c] = u;
        dfs(c);
        grundy[u] ^= grundy[c] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int nim_sum = grundy[1];
    ground[1] = true;

    for (int i = 1; i <= n; ++i) {
        int u = i;
        while (!ground[u]) {
            nim_sum ^= (grundy[u] + 1) ^ grundy[u] ^ 1;
            ground[u] = true;
            u = par[u];
        }

        cout << (nim_sum > 0 ? 1 : 2);
    }

    cout << "\n";
}