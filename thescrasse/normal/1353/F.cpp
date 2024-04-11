// 1353F
// Decreasing Heights

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define j1 treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, j1, k, k1, t, n, m, res, flag[10], a[maxn][maxn], b[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < maxn; i++) a[i][0] = INF;
    for (j = 0; j < maxn; j++) a[0][j] = INF;
    cin >> t;
    while (t--) {
        res = INF;
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> b[i][j];
                b[i][j] += (n + m - i - j);
            }
        }

        for (i1 = 1; i1 <= n; i1++) {
            for (j1 = 1; j1 <= m; j1++) {
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= m; j++) {
                        a[i][j] = b[i][j];
                        a[i][j] -= b[i1][j1];
                        if (a[i][j] < 0) a[i][j] = INF;
                    }
                }

                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= m; j++) {
                        if (i + j == 2) continue;
                        a[i][j] += min(a[i - 1][j], a[i][j - 1]);
                        a[i][j] = min(a[i][j], INF);
                    }
                }
                res = min(res, a[n][m]);
            }
        }

        cout << res << endl;
    }

    return 0;
}