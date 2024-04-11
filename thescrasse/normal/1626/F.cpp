#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 10000010
#define maxp 720730
#define maxk 18

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll xx, yy, mm, dp[maxk][maxp], l, pw[maxk];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    l = 720720;
    cin >> n >> a[1] >> xx >> yy >> k >> mm;
    for (i = 2; i <= n; i++) {
        a[i] = (a[i - 1] * xx + yy) % mm;
    }

    pw[0] = 1;
    for (i = 1; i < maxk; i++) pw[i] = (n * pw[i - 1]) % mod;

    res = 0;
    for (i = 1; i <= n; i++) res = (res + (a[i] - (a[i] % l))) % mod;
    res = (res * k) % mod;
    res = (res * pw[k - 1]) % mod;

    for (i = 1; i <= n; i++) dp[0][a[i] % l]++;

    for (i = 1; i <= k; i++) {
        for (j = 0; j < l; j++) res = (res + (j * dp[i - 1][j] % mod * pw[k - i])) % mod;
        if (i == k) continue;
        for (j = 0; j < l; j++) {
            dp[i][j] = (dp[i][j] + (n - 1) * dp[i - 1][j]) % mod;
            dp[i][j - (j % i)] = (dp[i][j - (j % i)] + dp[i - 1][j]) % mod;
        }
    }

    cout << res << nl;

    return 0;
}