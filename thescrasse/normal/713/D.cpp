#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define y1 gneriongiero

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010
#define maxl 10
#define maxq 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p2[maxn];
ll mt[maxn][maxn], ps[maxn][maxn], q, bsl[maxq], bsm, bsu[maxq];
ll x1[maxq], y1[maxq], x2[maxq], y2[maxq], l1, l2, bl, bm, bu, ty;
int jm[maxl][maxl][maxn][maxn];

ll rs(ll x1, ll y1, ll x2, ll y2) {
    if (x1 <= 0 || y1 <= 0 || x2 > n || y2 > m) return -1;
    return (ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1]);
}

ll rmq(ll x1, ll y1, ll x2, ll y2) {
    ll px, py, x3, y3;
    if (x1 <= 0 || y1 <= 0 || x1 > x2 || y1 > y2 || x2 > n || y2 > m) return -1;
    px = p2[x2 - x1 + 1]; py = p2[y2 - y1 + 1];
    x3 = x2 - (1 << px) + 1; y3 = y2 - (1 << py) + 1;
    return max({jm[px][py][x1][y1], jm[px][py][x3][y1],
        jm[px][py][x1][y3], jm[px][py][x3][y3]});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 2; i < maxn; i++) p2[i] = p2[i / 2] + 1;

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
            ps[i][j] = mt[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            bl = 0; bu = 2000;
            while (bl != bu) {
                bm = (bl + bu + 1) / 2;
                if (rs(i, j, i + bm - 1, j + bm - 1) == bm * bm) bl = bm;
                else bu = bm - 1;
            }
            jm[0][0][i][j] = bl;
        }
    }

    for (l1 = 0; l1 < 10; l1++) {
        for (l2 = l1; l2 < 10; l2++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= m; j++) {
                    if (l1 + l2 == 0) continue;
                    k = min(j + (1 << (l2 - 1)), m + 1);
                    jm[l1][l2][i][j] = max(jm[l1][l2 - 1][i][j], jm[l1][l2 - 1][i][k]);
                    k = min(i + (1 << (l2 - 1)), n + 1);
                    jm[l2][l1][i][j] = max(jm[l2 - 1][l1][i][j], jm[l2 - 1][l1][k][j]);
                }
            }
        }
    }

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        bsl[i] = 0; bsu[i] = 1000;
    }

    for (ty = 1; ty <= 10; ty++) {
        for (i = 1; i <= q; i++) {
            bsm = (bsl[i] + bsu[i] + 1) / 2;
            k = rmq(x1[i], y1[i], x2[i] - bsm + 1, y2[i] - bsm + 1);
            if (k >= bsm) bsl[i] = bsm;
            else bsu[i] = bsm - 1;
        }
    }

    for (i = 1; i <= q; i++) cout << bsl[i] << nl;

    return 0;
}