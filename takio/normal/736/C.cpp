#include <bits/stdc++.h>
using namespace std;

const int N = 110, K = 25, mod = 1e9 + 7;

int dp[N][K][K], tmp[K][K];
int n, x;
vector <int> g[N];

void add (int &u, int v) { u += v; if (u >= mod) u -= mod; }

void dfs (int u, int fa) {
    dp[u][0][0] = 1;
    dp[u][x + 1][1] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
        memset (tmp, 0, sizeof tmp);
        for (int j = 0; j <= x + 1; j++) {
            for (int k = 0; k <= x + 1; k++) {
                for (int l = 0; l <= x + 1; l++) {
                    for (int o = 0; o <= x + 1; o++) {
                        int mx = 0;
                        if (o && j + o > x) mx = max (mx, o + 1);
                        if (k && k + l > x) mx = max (mx, k);
//                        cout <<
                        add (tmp[min (j, l + 1)][mx], 1LL * dp[u][j][k] * dp[v][l][o] % mod);
                    }
                }
            }
        }
        memcpy (dp[u], tmp, sizeof tmp);
    }
//    for (int j = 0; j <= x + 1; j++)
//            for (int k = 0; k <= x + 1; k++) if (dp[u][j][k]) cout << u << ' ' << j << ' ' << k << ' ' << dp[u][j][k] <<endl;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> x;
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    dfs (1, 0);
    int r = 0;
    for (int i = 0; i <= x; i++) add (r, dp[1][i][0]);
    cout << r;
}