#include <bits/stdc++.h>
using namespace std;

const int N = 4000 + 1;

vector<int> adj[N];
bool know[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        know[u][v] = know[v][u] = true;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            for (int k : adj[i]) {
                if (know[j][k]) {
                    ans = min(ans, (int) (adj[i].size() + adj[j].size() + adj[k].size()) - 6);
                }
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}