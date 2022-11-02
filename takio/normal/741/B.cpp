#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1100;
int a[N], b[N];
vector <int> g[N];
int na, nb, nn, dp[2][N], vis[N], c[N];

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = 1;
    c[++nn] = u;
    na += a[u];
    nb += b[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs (v);
    }
}

void up (int &a, int b) {
    if (a < b) a = b;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &b[i]);
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    memset (dp, -1, sizeof dp);
    dp[0][0] = 0;
    int now = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        memset (dp[now ^ 1], -1, sizeof dp[now ^ 1]);
        na = nb = nn = 0;
        dfs (i);
//        cout << nn << endl;
        for (int j = 0; j <= w; j++) if (dp[now][j] != -1) {
            up (dp[now ^ 1][j], dp[now][j]);
            if (j + na <= w)up (dp[now ^ 1][j + na], dp[now][j] + nb);
            for (int k = 1; k <= nn; k++) {
                int u = c[k];
                if (j + a[u] <= w) up (dp[now ^ 1][j + a[u]], dp[now][j] + b[u]);
            }
        }
        now ^= 1;
    }
    int res = 0;
    for (int i = 0; i <= w; i++) up (res, dp[now][i]);
    cout << res << endl;
}