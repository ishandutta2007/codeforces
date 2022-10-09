// 1316E
// Team Building

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], b, p, dp[maxn][138], x, w;
array<ll, 8> a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> p >> k;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 7; j++) {
            a[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        cin >> a[i][0];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= p; j++) {
            cin >> a[i][j];
        }
    }

    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);

    m = 1 << p;
    dp[0][0] = 0;
    for (j = 1; j < m; j++) {
        dp[0][j] = -INF;
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j] = -INF;
            x = __builtin_popcountll(j);
            for (b = 0; b < p; b++) {
                if (!((j >> b) & 1)) continue;
                w = j - (1 << b);
                dp[i][j] = max(dp[i][j], dp[i - 1][w] + a[i][b + 1]);
            }

            if (i <= x + k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][0]);
            } else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j < m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    cout << dp[n][m - 1];

    return 0;
}