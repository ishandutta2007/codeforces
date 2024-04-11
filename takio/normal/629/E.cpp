#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 100010, F = 20;

int f[N][F], d[N], sz[N], n;
LL sum1[N], sum2[N];
vector <int> g[N];

void dfs1 (int u, int fa, int dep) {
    f[u][0] = fa;
    d[u] = dep;
    sz[u] = 1;
    for (int i = 1; i < F; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs1 (v, u, dep + 1);
        sz[u] += sz[v];
        sum1[u] += sum1[v] + sz[v];
    }
}

//map <int, int> mp;

void dfs2 (int u, int fa, LL val) {
//    mp[u] = ffa;
    sum2[u] = val;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs2 (v, u, val + n - 2 * sz[v]);
    }
}

int getlca (int u, int v) {
    if (d[u] < d[v]) swap (u, v);
    int h = d[u] - d[v];
    for (int i = 0; i < F; i++) if (h & (1 << i)) {
        u = f[u][i];
    }
    if (u == v) return u;
    for (int i = F - 1; i >= 0; i--) if (f[u][i] != f[v][i]) {
        u = f[u][i];
        v = f[v][i];
    }
    return f[u][0];
}

void getres (int len, int sz1, int sz2, LL sum1 ,LL sum2) {
//    cout << len << ' ' << sz1 <<' ' << sz2 << ' ' << sum1 << ' ' << sum2 << endl;
    long double res = 0;
    res += (long double)sum1 * sz2 + (long double)sum2 * sz1;
    res /= (long double)sz1 * sz2;
//    res *= sum2;
//    res /= sz1;
//    res /= sz2;
    res += len + 1;
    printf ("%.10f\n", (double) res);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int m, u, v;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
//    g[0].push_back (1);
    dfs1 (1, 0, 0);
    dfs2 (1, 0, sum1[1]);
//    for (int i = 1; i <= n; i++) cout << sum2[i] << ' '; cout << endl;
    while (m--) {
        scanf ("%d%d", &u, &v);
        if (d[u] < d[v]) swap (u, v);
        int l = getlca (u, v);
        if (l != v) {
            getres (d[v] - d[l] + d[u] - d[l], sz[u], sz[v], sum1[u], sum1[v]);
        } else {
            int h = d[u] - d[v] - 1;
            int fa = u;
            for (int i = 0; i < F; i++) if (h & (1 << i)) {
                fa = f[fa][i];
            }
//            cout << fa << endl;
            getres (d[v] - d[l] + d[u] - d[l], sz[u], n - sz[fa], sum1[u], sum2[v] - sum1[fa] - sz[fa]);
        }
    }
}