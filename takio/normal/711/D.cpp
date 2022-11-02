#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const LL N = 200100, mod = 1e9 + 7;

vector <pii> g[N];
int r, f[N], vis[N], d[N];

void dfs (int u, int fa, int dep) {
//    cout << u << ' ' << fa << ' ' << endl;
    if (vis[u]) {
        if (r == 0) r = dep - d[u];
        return;
    }
    d[u] = dep;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        pii x = g[u][i];
        int v = x.xx;
        if (x.yy == fa) continue;
        dfs (v, x.yy, dep + 1);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        g[a].push_back (pii (i, i));
        g[i].push_back (pii (a, i));
    }
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * 2 % mod;
    LL res = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        r = 0;
        dfs (i, 0, 0);
//        cout << r << endl;
        (res *= f[r] - 2) %= mod;
        sum += r;
    }
    (res *= f[n - sum]) %= mod;
    cout << res << endl;
}