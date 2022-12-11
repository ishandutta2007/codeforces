#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 7;
int tin[N], tout[N], par[N], depth[N];
vector <int> g[N];
int T = 0;

void dfs(int v, int p = -1, int d = 0) {
    tin[v] = T++;
    depth[v] = d;
    par[v] = p;
    for (int u : g[v]) {
        if (u != p) dfs(u, v, d + 1);
    }
    tout[v] = T - 1;
}

bool is_ancestor(int v, int u) {
    if (v == -1) return 0;
    return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector <int> v(k);
        int u = -1;
        for (int j = 0; j < k; j++) {
            cin >> v[j];
            if (j == 0 || depth[v[j]] > depth[u]) u = v[j];
        }
        bool flag = 1;
        for (int j = 0; j < k; j++) {
            if (is_ancestor(v[j], u) || is_ancestor(par[v[j]], u)) continue;
            flag = 0;
            break;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}