#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, st;
ll h[maxn][maxn], v[maxn][maxn], dp[20][maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m - 1; j++) {
            cin >> h[i][j]; // (i, j) -> (i, j + 1)
        }
    }
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= m; j++) {
            cin >> v[i][j]; // (i, j) -> (i + 1, j)
        }
    }

    if (k % 2) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << -1 << ' ';
            }
            cout << nl;
        }
        return 0;
    }

    for (st = 0; st <= k / 2; st++) {
        for (i = 0; i <= n + 1; i++) {
            for (j = 0; j <= m + 1; j++) {
                dp[st][i][j] = INF;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            dp[0][i][j] = 0;
        }
    }

    for (st = 1; st <= k / 2; st++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                dp[st][i][j] = min({
                    dp[st - 1][i - 1][j] + v[i - 1][j],
                    dp[st - 1][i + 1][j] + v[i][j],
                    dp[st - 1][i][j - 1] + h[i][j - 1],
                    dp[st - 1][i][j + 1] + h[i][j]
                });
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << 2 * dp[k / 2][i][j] << ' ';
        }
        cout << nl;
    }

    return 0;
}