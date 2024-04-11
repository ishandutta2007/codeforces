#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

set<array<int, 2>> adj[2 * N];
int ans[N], parity;

void dfs(int u, bool circuit) {
    while (!adj[u].empty() && (circuit || adj[u].size() % 2 == 1)) {
        auto [c, i] = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        adj[c].erase({u, i});

        dfs(c, circuit);

        ans[i] = parity;
        parity ^= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        adj[r - 1].insert({N + c - 1, i});
        adj[N + c - 1].insert({r - 1, i});
    }

    for (int i = 0; i < 2 * N; ++i) {
        if (adj[i].size() % 2 == 1) {
            dfs(i, false);
        }
    }

    for (int i = 0; i < 2 * N; ++i) {
        if (!adj[i].empty()) {
            dfs(i, true);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (ans[i] == 0 ? 'r' : 'b');
    }
    cout << "\n";
}