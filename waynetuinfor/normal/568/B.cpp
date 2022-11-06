#include <bits/stdc++.h>
using namespace std;

const int maxn = 4000 + 10, mod = 1e9 + 7;
int dp[maxn][maxn], c[maxn][maxn];
bool v[maxn][maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int dfs(int n, int k) {
    if (n == 0) {
        if (k == 0) return 1;
        return 0;
    }
    if (v[n][k]) return dp[n][k];
    dp[n][k] = mul(dfs(n - 1, k), k);
    if (k > 0) dp[n][k] = add(dp[n][k], dfs(n - 1, k - 1));
    v[n][k] = true;
    // cout << "dp[" << n << "][" << k << "] = " << dp[n][k] << endl;
    return dp[n][k];
}

int main() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j <= i; ++j) {
            c[i][j] = c[i - 1][j];
            if (j > 0) c[i][j] = add(c[i][j], c[i - 1][j - 1]);
        }
    }
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) ans = add(ans, mul(dfs(i, j), c[n][i]));
    cout << ans << endl;
    return 0;
}