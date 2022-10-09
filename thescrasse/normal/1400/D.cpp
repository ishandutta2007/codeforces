#pragma pack(1)

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 3010

struct int_6 {
    unsigned short x;
    unsigned int y;
};

int_6 add(int_6 a, int_6 b) {
    int_6 r;
    ll c, d, k;
    k = ((ll)1 << 32) * a.x + a.y;
    k += ((ll)1 << 32) * b.x + b.y;
    c = k / ((ll)1 << 32); r.x = c;
    d = k % ((ll)1 << 32); r.y = d;
    return r;
}

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x;
int_6 dp[maxn][maxn][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                for (x = 0; x < 4; x++) {
                    dp[i][j][x] = {0, 0};
                }
            }
        }

        for (i = 1; i <= n; i++) {
            k = a[i];
            for (j = 1; j <= n; j++) {
                for (x = 3; x > 0; x--) {
                    if (x % 2 == 0) {
                        dp[k][j][x] = add(dp[k][j][x], dp[k][j][x - 1]);
                        // cout << k << ' ' << j << ' ' << x << ' ' << dp[k][j][x] << nl;
                    } else {
                        dp[j][k][x] = add(dp[j][k][x], dp[j][k][x - 1]);
                        // cout << j << ' ' << k << ' ' << x << ' ' << dp[j][k][x] << nl;
                    }
                }
                dp[k][j][0] = add(dp[k][j][0], {0, 1});
                // cout << k << ' ' << j << ' ' << 0 << ' ' << dp[k][j][0] << nl;
            }
        }

        res = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                res += (((ll)1 << 32) * dp[i][j][3].x) + dp[i][j][3].y;
            }
        }

        cout << res << nl;
    }

    return 0;
}