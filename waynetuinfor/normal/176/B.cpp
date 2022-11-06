#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int dp[2][maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    string now = a;
    int k; cin >> k;
    int n = (int)a.length(), t = 0;
    for (int i = 0; i < a.length(); ++i) {
        // cout << now << endl;
        if (now == b) ++t;
        now = now.substr(1, n - 1) + now[0];
    }
    dp[0][0] = (a == b); dp[1][0] = (a != b);
    // cout << dp[0][0] << ' ' << dp[1][0] << endl;
    // cout << t << endl;
    for (int i = 1; i <= k; ++i) {
        dp[0][i] = add(mul(dp[0][i - 1], t - 1), mul(dp[1][i - 1], t));
        dp[1][i] = add(mul(dp[0][i - 1], n - t), mul(dp[1][i - 1], n - t - 1));
    }
    cout << dp[0][k] << endl;
    return 0;
}