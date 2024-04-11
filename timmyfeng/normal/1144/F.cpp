#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

array<int, 2> edge[N];
vector<int> adj[N];
int color[N];

bool dfs(int u) {
    for (auto c : adj[u]) {
        if (color[c] == -1) {
            color[c] = 1 - color[u];
            if (!dfs(c)) {
                return false;
            }
        } else if (color[c] + color[u] != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(color + 2, color + n + 1, -1);

    if (dfs(1)) {
        cout << "YES\n";
        for (int i = 0; i < m; ++i) {
            cout << color[edge[i][0]]; 
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}