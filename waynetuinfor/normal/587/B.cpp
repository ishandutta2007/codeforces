#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
int a[maxn], na[maxn], ps[maxn];

inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; long long l; cin >> n >> l >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) cin >> a[i], na[i] = a[i];
    sort(na + 1, na + n + 1);
    for (int i = 1; i <= n; ++i) ps[i] = upper_bound(na + 1, na + n + 1, na[i]) - na - 1;
    for (int i = 1; i <= n; ++i) 
    if (k * 1ll * n > l) {
        int prv = 0, ans = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= k; ++i) {
            if (i * 1ll * n > l) break;
            prv = i;
            for (int j = 1; j < n + 1; ++j) dp[i - 1][j] = add(dp[i - 1][j], dp[i - 1][j - 1]);
            int now = 0;
            for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][ps[j]], now = add(now, dp[i][j]);
            ans = add(ans, mul(now, (l / n - i + 1) % mod));
        }
        if (prv < k) {
            dp = vector<vector<int>>(k + 1, vector<int>(n + 1));
            ans = add(ans, l % n);
            for (int i = 1; i <= l % n; ++i) {
                int pos = lower_bound(na + 1, na + n + 1, a[i]) - na;
                ++dp[0][pos];
            }
            for (int i = 1; i <= n; ++i) ps[i] = lower_bound(na + 1, na + n + 1, na[i]) - na;
            for (int i = 1; i <= prv; ++i) {
                for (int j = n - 1; j >= 0; --j) dp[i - 1][j] = add(dp[i - 1][j], dp[i - 1][j + 1]);
                for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][ps[j]], ans = add(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    int ans1 = 0, ans2 = 0;
    dp[0][0] = 1;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < n + 1; ++j) dp[i - 1][j] = add(dp[i - 1][j], dp[i - 1][j - 1]);
        int now = 0;
        for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][ps[j]], now = add(now, dp[i][j]);
        ans = add(ans, mul(now, (l / n - i + 1) % mod));
    }
    vector<int> tmp(dp[k - 1].begin(), dp[k - 1].end());
    for (int j = 1; j < n + 1; ++j) tmp[j] = add(tmp[j], tmp[j - 1]);
    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(na + 1, na + n + 1, a[i]) - na - 1;
        dp[k][i] = tmp[pos];
        ans1 = add(ans1, dp[k][i]);
    }
    for (int i = 1; i <= l % n; ++i) {
        int pos = upper_bound(na + 1, na + n + 1, a[i]) - na - 1;
        dp[k][i] = tmp[pos];
        ans2 = add(ans2, dp[k][i]);
    }
    dp = vector<vector<int>>(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= l % n; ++i) {
        int pos = lower_bound(na + 1, na + n + 1, a[i]) - na;
        ++dp[0][pos];
    }
    if (k > 1) ans2 = add(ans2, l % n);
    for (int i = 1; i <= n; ++i) ps[i] = lower_bound(na + 1, na + n + 1, na[i]) - na;
    for (int i = 1; i < k - 1; ++i) {
        for (int j = n - 1; j >= 0; --j) dp[i - 1][j] = add(dp[i - 1][j], dp[i - 1][j + 1]);
        for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][ps[j]], ans2 = add(ans2, dp[i][j]);
    }
    ans1 = mul(ans1, (l / n - k + 1) % mod);
    cout << add(ans, add(ans1, ans2)) << endl;
    return 0;
}