#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

vector <int> g[N];
int h[N], sz[N], f[N][20];

void dfs (int u, int fa) {
    sz[u] = 1;
    f[u][0] = fa;
    for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = 0; i < (int)g[u].size (); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        h[v] = h[u] + 1;
        dfs (v, u);
        sz[u] += sz[v];
    }
}

int lca (int x, int y) {
    if (h[x] < h[y]) swap (x, y);
    int t = h[x] - h[y];
    for (int i = 0; i < 20; i++)
        if (t & (1 << i)) x = f[x][i];
    for (int i = 19; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    if (x == y) return x;
    return f[x][0];
}

int main () {
//    cout << 'x';
//        freopen ("in.txt", "r", stdin);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    h[1] = 1;
    dfs (1, 0);
//    for (int i = 1; i <= n; i++) cout << i << ' ' << h[i] << ' ' << sz[i] << endl;
    int q, x, y;
    cin >> q;
    while (q--) {
        scanf ("%d%d", &x, &y);
        if (h[x] < h[y]) swap (x, y);
        if (x == y) printf ("%d\n", n);
        else if ((h[x] - h[y]) & 1) printf ("0\n");
        else {
            int xy = lca (x, y), tx = x;
//            cout << "lca " << xy << endl;
            int t = (h[x] + h[y] - 2 * h[xy]) / 2 - 1;
            for (int i = 0; i < 20; i++) if (t & (1 << i)) x = f[x][i];
//            cout << t << ' '<< x << endl;
            if (h[tx] == h[y]) {
                t = h[y] - h[xy] - 1;
//                cout << "t" << t << endl;
                for (int i = 0; i < 20; i++) if (t & (1 << i)) y = f[y][i];
                printf ("%d\n", n - sz[x] - sz[y]);
            } else printf ("%d\n", sz[f[x][0]] - sz[x]);
        }
    }
}