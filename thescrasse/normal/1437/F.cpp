#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll dp[maxn][maxn], ps[maxn][maxn], pv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    dp[0][0] = 1;
    for (i = 0; i <= n; i++) ps[i][0] = 1;
    for (i = 1; i <= n; i++) {
        while (2 * a[pv] <= a[i]) pv++;
        for (j = 1; j <= n; j++) {
            dp[i][j] = (dp[i][j] + ps[pv - 1][j - 1]) % mod;
            dp[i][j] = (dp[i][j] + max((ll)0, pv - j + 1) * dp[i][j - 1]) % mod;
            ps[i][j] = (ps[i - 1][j] + dp[i][j]) % mod;
        }
    }

    cout << dp[n][n] << nl;

    return 0;
}