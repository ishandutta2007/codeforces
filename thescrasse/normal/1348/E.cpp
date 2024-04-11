#pragma GCC optimize("Ofast")

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll rm, mx, jh, kh, tt, dp[maxn][maxn], x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;

    for (i = 1; i <= n; i++) {
        rm = (a[i] + b[i]) % m; res += ((a[i] + b[i]) / m); tt += (a[i] + b[i]);
        for (j = 0; j < m; j++) {
            jh = (tt - j + m) % m;
            for (k = 0; k < m; k++) {
                kh = rm - k;
                if (kh < 0) kh += m;
                if (k > a[i]) continue;
                if (kh > b[i]) continue;
                // cout << i _ j _ jh _ k _ kh << nl;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k + m * (j < k)] + (j < k) + (jh < kh) - (rm < k));
                mx = max(mx, dp[i][j]);
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    res += mx;
    cout << res << nl;

    return 0;
}