#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const long long inf = 1e18;
long long c[maxn], cost[maxn], dp[2][maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long w, b, x; cin >> n >> w >> b >> x;
    for (int i = 1; i <= n; ++i) cin >> c[i], s[i] = s[i - 1] + c[i];
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    fill(dp[0], dp[0] + maxn, -inf);
    dp[0][0] = w;
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        fill(dp[cur], dp[cur] + maxn, -inf);
        for (int j = 0; j <= s[i]; ++j) {
            for (int k = 0; k <= c[i]; ++k) if (dp[cur ^ 1][j - k] >= 0) {
                dp[cur][j] = max(dp[cur][j], min(dp[cur ^ 1][j - k] + x, w + b * (j - k)) - cost[i] * k);
            }
        }
        cur ^= 1;
    }
    cur ^= 1;
    for (int i = s[n]; i >= 0; --i) if (dp[cur][i] >= 0) return cout << i << endl, 0;
}