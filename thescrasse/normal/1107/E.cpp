// 1107E
// Vasya and Binary String

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[210], b, p, dp[maxn][maxn][maxn], l;
string s;

void solve(ll l, ll r, ll p) {
    if (l != r && s[l + 1] == s[l]) {
        ll k = 0;
        for (i = l + 1; i <= r; i++) {
            if (s[i] == s[i - 1]) k++;
            else break;
        }

        dp[l][r][p] = dp[l + k][r][p + k]; return;
    }

    flag[0] = 1;
    for (i = l; i <= r; i++) {
        if (i == r || s[i + 1] != s[l]) {
            // cout << l << ' ' << r << ' ' << p << " -> " << i + 1 << ' ' << r << ", " << p + i - l + 1 << nl;
            dp[l][r][p] = dp[i + 1][r][0] + a[p + i - l + 1];
            flag[0] = 0; break;
        }
    }

    if (flag[0] == 1) dp[l][r][p] = a[p + r - l + 1];

    if (p == n) return;
    for (i = l + 1; i < r; i++) {
        if (s[i] != s[l] && s[i + 1] == s[l]) {
            // cout << l << ' ' << r << ' ' << p << " -> " << i << ", " << p + 1 << nl;
            dp[l][r][p] = max(dp[l][r][p], dp[l + 1][i][0] + dp[i + 1][r][p + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 2; i <= 2 * n; i++) {
        for (j = 1; j < i; j++) {
            a[i] = max(a[i], a[j] + a[i - j]);
        }
    }

    for (k = 0; k < n; k++) {
        for (l = 0; l < n; l++) {
            if (l + k >= n) continue;
            for (p = 0; p <= n; p++) {
                solve(l, l + k, p);
                // cout << l << ' ' << l + k << ' ' << p << ' ' << dp[l][l + k][p] << nl;
            }
        }
    }

    cout << dp[0][n - 1][0] << nl;

    return 0;
}