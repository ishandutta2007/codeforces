#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, imp[2];
vector<int> adj[N];
int h[2][N], f[2][N];

void BFS(int st, int *h) {
    queue<int> q;
    q.push(st);
    h[st] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) if (!h[v]) { 
            h[v] = 1;
            q.push(v);
        }
    }
}

long long solve() { 
    for(int i = 0; i <= 1; i++) {
        fill(h[i], h[i] + n + 1, 0);
        h[i][imp[i ^ 1]] = 1;
        BFS(imp[i], h[i]);
    }
    for(int i = 1; i <= n; i++) {
        f[1][i] = f[0][i] = 2 * (h[0][i] && h[1][i]);
    }

    long long v[2];
    for(int i = 0; i <= 1; i++) {
        BFS(imp[i], f[i]);
        v[i] = count(f[i], f[i] + n + 1, 1) - 1;
    }
    return v[0] * v[1];
}
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> imp[0] >> imp[1];
        while (m--) {  
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << solve() << '\n';
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
}