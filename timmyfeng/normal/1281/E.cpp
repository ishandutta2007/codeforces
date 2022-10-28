#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> a, b, t;
vector<int> dep, sz;

void dfs(int v, int p) {
    dep[v] = dep[p] + 1;
    for (auto c : adj[v]) {
        if (c != p) {
            dfs(c, v);
            sz[v] += sz[c];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        a.resize(2 * k - 1);
        b.resize(2 * k - 1);
        t.resize(2 * k - 1);
        adj.assign(2 * k + 1, vector<int>());
        for (int i = 0; i < 2 * k - 1; ++i) {
            cin >> a[i] >> b[i] >> t[i];
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }

        dep.assign(2 * k + 1, 0);
        sz.assign(2 * k + 1, 1);
        dfs(1, 0);

        long long solMx = 0, solMn = 0;
        for (int i = 0; i < 2 * k - 1; ++i) {
            if (dep[a[i]] > dep[b[i]]) {
                swap(a[i], b[i]);
            }
            solMx += (long long) min(sz[b[i]], 2 * k - sz[b[i]]) * t[i];
            solMn += sz[b[i]] % 2 * t[i];
        }
        cout << solMn << ' ' << solMx << '\n';
    }
}