#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define y1 ngusdonheri

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w, m1, m2;
ll mt[maxn][maxn], dist[2][maxn][maxn], ty, x, y, x1, y1;
bool vis[maxn][maxn];
queue<array<ll, 2>> q;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

bool oob(ll x, ll y) {
    return (x < 1 || x > n || y < 1 || y > m || mt[x][y] == -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> w;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
        }
    }

    for (ty = 0; ty <= 1; ty++) {
        while (!q.empty()) q.pop();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                dist[ty][i][j] = INF;
            }
        }

        if (ty == 0) {
            q.push({1, 1}); dist[ty][1][1] = 0;
        } else {
            q.push({n, m}); dist[ty][n][m] = 0;
        }

        while (!q.empty()) {
            array<ll, 2> o = q.front(); q.pop();
            x = o[0]; y = o[1];
            for (i = 0; i < 4; i++) {
                x1 = x + dx[i]; y1 = y + dy[i];
                if (oob(x1, y1)) continue;
                if (dist[ty][x1][y1] != INF) continue;
                dist[ty][x1][y1] = dist[ty][x][y] + 1;
                q.push({x1, y1});
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << dist[0][i][j] << ' ';
        }
        cout << nl;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << dist[1][i][j] << ' ';
        }
        cout << nl;
    } */

    if (dist[0][n][m] != INF) res = w * dist[0][n][m];
    else res = INF;

    m1 = INF; m2 = INF;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (dist[0][i][j] != INF && mt[i][j] != 0) {
                m1 = min(m1, w * dist[0][i][j] + mt[i][j]);
            }
            if (dist[1][i][j] != INF && mt[i][j] != 0) {
                m2 = min(m2, w * dist[1][i][j] + mt[i][j]);
            }
        }
    }

    // cout << res _ m1 _ m2 << nl;

    res = min(res, m1 + m2);
    if (res == INF) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}