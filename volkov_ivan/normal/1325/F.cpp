#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5 + 7;
vector <int> g[N];
vector <int> path;
int depth[N];
int par[N];
bool poss[N];
bool vis[N];
int need;

void dfs(int v, int d = 0, int p = -1) {
    par[v] = p;
    depth[v] = d;
    vis[v] = 1;
    path.push_back(v);
    for (int u : g[v]) {
        if (vis[u] && depth[v] - depth[u] + 1 >= need) {
            cout << 2 << endl;
            cout << depth[v] - depth[u] + 1 << endl;
            int cur = v;
            while (cur != par[u]) {
                cout << cur << ' ';
                cur = par[cur];
            }
            exit(0);
        }
        if (!vis[u]) dfs(u, d + 1, v);
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    need = floor(sqrt(n));
    for (int i = 1; i <= n; i++) poss[i] = 1;
    while (need * need < n) need++;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    vector <int> good;
    for (int i = n - 1; i >= 0; i--) {
        if (!poss[path[i]]) continue;
        good.push_back(path[i]);
        for (int u : g[path[i]]) {
            poss[u] = 0;
        }
        if ((int) good.size() == need) {
            cout << 1 << endl; 
            for (int elem : good) {
                assert(poss[elem]);
                cout << elem << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    return -1;
}