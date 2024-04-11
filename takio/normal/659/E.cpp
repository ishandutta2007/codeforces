#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

vector <int> g[100100];
int vis[100100];

int dfs (int u, int fa) {
    if (vis[u]) return 1;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        if (dfs (v, u)) return 1;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);

        g[u].push_back (v);
        g[v].push_back (u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        res += dfs (i, 0) ^ 1;
    }
    cout << res << endl;
}