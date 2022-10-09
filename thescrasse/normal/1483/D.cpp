// 1483D
// Useful Edges

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 610

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w, q;
ll dist[maxn][maxn], tr[maxn][maxn], us[maxn][maxn], dg[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = INF;
            tr[i][j] = -INF; dg[i][j] = INF;
        }
    }
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        dist[a][b] = w; dist[b][a] = w;
        dg[a][b] = w; dg[b][a] = w;
    }
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> a >> b >> w; tr[a][b] = w; tr[b][a] = w;
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << nl;
    }
    cout << nl; */

    for (i = 1; i <= n; i++) {
        for (b = 1; b <= n; b++) {
            m = -INF;
            for (j = 1; j <= n; j++) {
                if (i == j) continue;
                m = max(m, tr[i][j] - dist[b][j]);
            }
            // cout << "i, b, m = " << i _ b _ m << nl;
            for (a = 1; a <= b - 1; a++) {
                // cout << "a, dist, dg, m = " << a _ dist[i][a] _ dg[a][b] _ m << nl;
                if (dist[i][a] + dg[a][b] <= m) us[a][b] = 1;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            res += us[i][j];
        }
    }

    cout << res << nl;

    return 0;
}