#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 1010
#define maxm 100010

int i, i1, j, k, k1, t, n, m, flag[10], a[maxn], b;
ll res, dp[maxm][2], ps[maxm][2];

ll solve(ll x) {
    // if (x == 1 || x == 2 || x == 4 || x == 6) cout << "solve" _ x << nl;
    ll i, j, k, l, r;
    for (i = 0; i < maxm; i++) {
        for (j = 0; j <= 1; j++) {
            ps[i][j] = (i >= 1 && j == 0);
        }
    }

    for (k = 1; k <= m; k++) {
        l = 0; r = 0;
        for (i = 1; i <= n; i++) {
            while (l <= i - 1 && a[i] - a[l + 1] > x) l++;
            r = l;
            while (r <= i - 1 && a[i] - a[r + 1] >= x) r++;
            dp[i][0] = ps[l][0];
            dp[i][1] = (ps[r][1] + ps[r][0] - ps[l][0] + mod) % mod;
            // if (x == 1 || x == 2 || x == 4 || x == 6) cout << dp[i][0] _ dp[i][1] << "  ";
        }
        // if (x == 1 || x == 2 || x == 4 || x == 6) cout << nl;

        for (i = 1; i <= n; i++) {
            for (j = 0; j <= 1; j++) {
                ps[i][j] = (ps[i - 1][j] + dp[i][j]) % mod;
            }
        }
    }

    // if (ps[n][1] != 0) cout << "solve" _ x _ ps[n][1] << nl;
    return ps[n][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; n++; a[1] = -INF;
    for (i = 2; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    if (m == 2) {
        for (i = 2; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                res = (res + a[j] - a[i]) % mod;
            }
        }

        cout << res << nl; return 0;
    }

    if (m == 3) {
        for (i = 2; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                for (k = j + 1; k <= n; k++) {
                    res = (res + min(a[j] - a[i], a[k] - a[j])) % mod;
                }
            }
        }

        cout << res << nl; return 0;
    }

    for (i = 1; i <= 100000 / (m - 1); i++) {
        res = (res + ((ll)i * solve(i))) % mod;
    }

    cout << res << nl;

    return 0;
}