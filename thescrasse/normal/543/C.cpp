// 543C
// Remembering Strings

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 30

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], mk, dp[1049000], mkk, x, cr, mx;
string s[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> s[i]; s[i] = '#' + s[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
        }
    }

    for (mk = 1; mk < (1 << n); mk++) {
        // cout << "mk = " << mk << nl;
        dp[mk] = INF;
        b = (mk & (-mk)); x = 1;
        while (b >>= 1) x++;
        for (j = 1; j <= m; j++) dp[mk] = min(dp[mk], dp[mk & ~(1 << (x - 1))] + mt[x][j]);

        for (j = 1; j <= m; j++) {
            mkk = mk; cr = 0; mx = 0; flag[0] = 1;
            for (i = 1; i <= n; i++) {
                if (s[i][j] == s[x][j]) {
                    // if (((mk >> (i - 1)) & 1) == 0) flag[0] = 0;
                    mkk &= ~(1 << (i - 1)); cr += mt[i][j]; mx = max(mx, mt[i][j]);
                }
            }
            // cout << "j, cr, mx, mkk, dp = " << j _ cr _ mx _ mkk _ dp[mkk] << nl;
            dp[mk] = min(dp[mk], cr - mx + dp[mkk]);
        }
    }

    // for (i = 0; i < (1 << n); i++) cout << i _ dp[i] << nl;

    res = dp[(1 << n) - 1];

    cout << res << nl;

    return 0;
}