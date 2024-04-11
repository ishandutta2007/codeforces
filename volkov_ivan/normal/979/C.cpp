#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5;
vector <int> g[MAX_N + 1];
vector <int> path;
int x, y;

bool dfs1(int v, int prev = -1) {
    if (v == y) {
        path.push_back(v);
        return 1;
    }
    for (int u : g[v]) {
        if (u == prev) continue;
        if (dfs1(u, v)) {
            path.push_back(v);
            return 1;
        }
    }
    return 0;
}

int dfs2(int v, int prev) {
    int sz = 1;
    for (int u : g[v]) {
        if (u == prev) continue;
        sz += dfs2(u, v);
    }
    return sz;
}

int main() {
    ios_base :: sync_with_stdio(0);
    int n, v, u;
    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs1(x);
    long long ans, a, b;
    ans = (long long) n * (n - 1);
    a = dfs2(x, path[path.size() - 2]);
    b = dfs2(y, path[1]);
    ans -= a * b;
    cout << ans << endl;
}