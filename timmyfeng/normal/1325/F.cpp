#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

vector<int> adj[MX + 1];
bitset<MX + 1> used, vstd;
int par[MX + 1], dep[MX + 1];
vector<int> ans;
int sq;

void dfs(int u) {
    vstd[u] = true;
    for (auto c : adj[u]) {
        if (c == par[u]) continue;
        if (vstd[c]) {
            if (dep[u] - dep[c] >= sq - 1) {
                cout << 2 << '\n';
                cout << dep[u] - dep[c] + 1 << '\n';
                for (int i = u; i != par[c]; i = par[i]) {
                    cout << i << ' ';
                }
                exit(0);
            }
        } else {
            dep[c] = dep[u] + 1;
            par[c] = u;
            dfs(c);
        }
    }
    if (!used[u]) {
        ans.push_back(u);
        for (auto i : adj[u]) {
            used[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    sq = ceil(sqrt(n));
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << 1 << '\n';
    for (int i = 0; i < sq; ++i) {
        cout << ans[i] << ' ';
    }
}