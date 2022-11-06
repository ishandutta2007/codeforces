#include <bits/stdc++.h>
using namespace std;

const int maxn = 77, maxb = 20, mod = 1e9 + 7;
int dp[maxn][1 << maxb];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int main() {
    int n; cin >> n;
    string s; cin >> s; s = '.' + s;
    // dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        // cout << "i = " << i << endl;
        for (int j = 0; j < (1 << maxb); ++j) if (dp[i][j]) {
            int now = 0;
            // cout << "j = " << j << endl;
            for (int k = i; k <= n; ++k) {
                // cout << "k = " << k << endl;
                now = now << 1 | (s[k] - '0');
                // cout << "now = " << now << endl;
                if (now > maxb) break;
                if (now == 0) continue;
                if ((j | (1 << (now - 1))) >= (1 << maxb)) continue;
                dp[k + 1][j | (1 << (now - 1))] = add(dp[k + 1][j | (1 << (now - 1))], dp[i][j]);
            }
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    } 
    int ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
        for (int mask = 1; mask < (1 << maxb); mask = mask << 1 | 1) ans = add(ans, dp[i][mask]);
    }
    cout << ans << endl;
    return 0;
}