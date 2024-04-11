#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 24, mod = 1e9 + 7;
int a[1 << maxn], forb[maxn], n, k, dp[1 << maxn];
long long d[1 << maxn];
bool v[1 << maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int dfs(int s) {
    if (s == 0) {
        for (int i = 0; i < k; ++i) if (forb[i] == 0) return 0;
        return 1;
    }
    for (int i = 0; i < k; ++i) if (d[s] == forb[i]) return 0;
    if (v[s]) return dp[s];
    dp[s] = 0;
    int now = s;
    while (now) {
        dp[s] = add(dp[s], dfs(s ^ (now & -now)));
        now -= (now & -now);
    }
    v[s] = true;
    // cout << "dp[" << s << "] = " << dp[s] << endl;
    return dp[s];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[1 << i];
    for (int i = 0; i < (1 << n); ++i) {
        int now = i;
        while (now) d[i] += a[(now & -now)], now -= (now & -now);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> forb[i];
    dp[0] = 1;
    for (int i = 0; i < (1 << n); ++i) {
        int now = i; 
        bool ok = true;
        for (int j = 0; j < k; ++j) if (d[i] == forb[j]) ok = false;
        if (!ok) continue;
        while (now) dp[i] = add(dp[i], dp[i ^ (now & -now)]), now -= (now & -now);
        // cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}