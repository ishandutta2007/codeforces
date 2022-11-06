#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int dp[maxn][maxn], suf[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dp[0][0] = 1;
    char prv = 's';
    for (int j = n; j >= 0; --j) suf[j] = add(suf[j + 1], dp[0][j]);
    for (int i = 1; i <= n; ++i) {
        char c; cin >> c;
        for (int j = 0; j <= n; ++j) {
            if (j && prv == 'f') dp[i][j] = dp[i - 1][j - 1];
            else if (prv == 's') dp[i][j] = suf[j];
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        } 
        memset(suf, 0, sizeof(suf));
        for (int j = n; j >= 0; --j) suf[j] = add(suf[j + 1], dp[i][j]);
        prv = c;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) ans = add(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}