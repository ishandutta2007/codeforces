#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 2000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][3], df[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    dp[0][2] = 0; dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 0;
    for (i = 2; i <= 2000000; i++) {
        dp[i][0] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod;
        dp[i][1] = dp[i - 1][0] % mod;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
    }

    for (i = 1; i <= 2000000; i++) {
        df[i] = (dp[i][2] - dp[i - 1][2] + mod) % mod;
    }

    for (i = 1; i <= 2000000; i++) {
        if (i >= 4) {
            df[i] += df[i - 3]; df[i] %= mod;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (4 * df[n]) % mod << nl;
    }

    return 0;
}