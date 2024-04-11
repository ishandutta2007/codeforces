// 449D
// Jzzhu and Numbers

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[21][1048586], p2[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; m = (1 << 20);
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    p2[0] = 1;
    for (i = 1; i <= 1000000; i++) p2[i] = (2 * p2[i - 1]) % mod;

    for (i = 0; i < m; i++) {
        dp[0][i] = 0;
    }

    for (i = 0; i < n; i++) {
        dp[0][a[i]]++;
    }

    for (i = 1; i <= 20; i++) {
        for (j = 0; j < m; j++) {
            if ((j >> (i - 1)) & 1 == 1) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + (1 << (i - 1))];
            }
        }
    }

    res = 0;
    for (j = 0; j < m; j++) {
        if (j == 0) k = 0;
        else k = __builtin_popcountll(j);
        res += p2[dp[20][j]] * (1 - 2 * (k % 2));
        res %= mod; res += mod; res %= mod;
    }

    cout << res;

    return 0;
}