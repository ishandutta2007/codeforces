#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 500010, F = 21;

vector <int> g[N], h[N];
int d[N], f[N][F], s[N], a[N];
LL c[N][F];

void dfs (int u, int fa, int cost) {
//    d[u] = d[fa] + 1;
    f[u][0] = fa;
    c[u][0] = cost;
    for (int i = 1; i < F; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
        c[u][i] = c[u][i - 1] + c[f[u][i - 1]][i - 1];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u, h[u][i]);
    }
}

void dfs (int u, int fa) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
        s[u] += s[v];
    }
//    res
}

int main () {
//    freopen ("in.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        g[i].clear();
        h[i].clear();
        s[i] = 0;
    }
    int u, x;
    for (int i = 2; i <= n; i++) {
        scanf ("%d%d", &u, &x);
        g[u].push_back (i);
        g[i].push_back (u);
        h[u].push_back (x);
        h[i].push_back (x);
    }
    dfs (1, 0, 0);
    for (int i = 1; i <= n; i++) {
        int u = i, now = a[i];
        for (int j = F - 1; j >= 0; j--) if (f[u][j] && now >= c[u][j]) {
            now -= c[u][j];
            u = f[u][j];
        }
        s[i]++;
        s[f[u][0]]--;
//            cout << i << ' ' << u << endl;
    }
    dfs (1, 0);
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf (" ");
        printf ("%d", s[i] - 1);
    }
}