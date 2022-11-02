#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 501000;

vector <int> g[N], g2[N];
int a[N], p[N], nn, d[N];

void dfs (int u, int fa) {
    if (a[u] != a[fa]) {
        p[u] = ++nn;
        g2[p[u]].push_back (p[fa]);
        g2[p[fa]].push_back (p[u]);
    } else p[u] = p[fa];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
    }
}

void dfs2 (int u, int fa) {
    d[u] = d[fa] + 1;
    for (int i = 0; i < g2[u].size(); i++) {
        int v = g2[u][i];
        if (v == fa) continue;
        dfs2 (v, u);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    a[0] = -1;
    dfs (1, 0);
    dfs2 (1, 0);
    int rt = -1;
    for (int i = 1; i <= n; i++) if (rt == -1 || d[rt] < d[i]) rt = i;
    d[rt] = 0;
    dfs2 (rt, 0);
    rt = -1;
    for (int i = 1; i <= n; i++) if (rt == -1 || d[rt] < d[i]) rt = i;
    cout << d[rt] / 2 << endl;
}