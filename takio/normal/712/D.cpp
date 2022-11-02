#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 210000, mod = 1e9 + 7;
int dp[110][N], sum[N];

int main () {
//    freopen ("in", "r", stdin);
    int a, b, k, t;
    cin >> a >> b >> k >> t;
//    int now = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
//        for (int j = 0; j <= (2 * k) * t; j++) cout << dp[i - 1][j] << endl;
        for (int j = 0; j < N; j++) sum[j] = ((j > 0 ? sum[j - 1] : 0) + dp[i - 1][j]) % mod;
        for (int j = 0; j < N; j++) dp[i][j] = (sum[j] - (j - 2 * k - 1 >= 0 ? sum[j - 2 * k - 1] : 0) + mod) % mod;
    }
    for (int j = 0; j < N; j++) sum[j] = ((j > 0 ? sum[j - 1] : 0) + dp[t][j]) % mod;
//    for (int j = 0; j <= (2 * k) * t; j++) cout << dp[t][j] << endl;
    int res = 0;
    for (int j = 0; j <= (2 * k) * t; j++) {
//        cout <<
        (res += 1LL * dp[t][j] * (j + a - b - 1 < 0 ? 0 : sum[j + a - b - 1]) % mod) %= mod;
    }
    cout << res << endl;
//    cout << res;
}