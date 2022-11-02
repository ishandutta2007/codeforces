#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
#define xx first
#define yy second
#define pii pair <int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 5010, INF = 0x3f3f3f3f;
int dp[N][N], pre[N][N], d[N], a[N];
vector <int> g[N], h[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, t, u, v, w;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &u, &v, &w);
        g[u].push_back (v);
        h[u].push_back (w);
        d[v]++;
    }
    queue <int> q;
    for (int i = 1; i <= n; i++) if (d[i] == 0) q.push (i);
    int nn = 0;
    while (!q.empty ()) {
        int u = q.front();
        a[++nn] = u;
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (--d[v] == 0) {
                q.push (v);
            }
        }
    }
    memset (dp, 0x3f, sizeof dp);
    dp[1][1] = 0;
//    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    for (int i = 1; i <= n; i++) {
        int u = a[i];
        for (int j = 0; j <= n; j++) if (dp[u][j] != INF) {
//            cout << u << ' ' << j << ' ' << dp[u][j] << endl;
            for (int k = 0; k < g[u].size(); k++) {
                int v = g[u][k];
                if (dp[v][j + 1] > dp[u][j] + h[u][k] && dp[u][j] + h[u][k] <= t) {
                    dp[v][j + 1] = dp[u][j] + h[u][k];
                    pre[v][j + 1] = u;
                }
            }
        }
    }
    int res;
//    , id;
//    for (int i = 1; i <= n; i++) if (a[i] == n) id = i;
//    cout << id << ' ' << dp[id][4] << endl;
    for (int i = n; i >= 1; i--) if (dp[n][i] <= t) {
        res = i;
        break;
    }
    cout << res << endl;
    vector <int> r;
    int now = n;
    while (now) {
        r.push_back (now);
        now = pre[now][res];
        res--;
    }
    for (int i = r.size() - 1; i >= 0; i--) {
        printf ("%d ", r[i]);
    }
}