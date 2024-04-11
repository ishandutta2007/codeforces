#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5;
vector <int> g[MAX_N + 1];
int colour[MAX_N + 1];
bool visited[MAX_N + 1];
bool ans[MAX_N + 1];

void dfs(int v, int c) {
    visited[v] = 1;
    colour[v] = c;
    for (int u : g[v]) {
        if (!visited[u]) dfs(u, c);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    int n, m, v, u, now = 0, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, now++);
    }
    for (int i = 0; i < now; i++) {
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() != 2) ans[colour[i]] = 0;
    }
    for (int i = 0; i < now; i++) {
        if (ans[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}