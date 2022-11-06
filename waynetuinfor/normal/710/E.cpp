#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7 + 10;
long long dp[maxn];

int main() {
    int n, x, y; cin >> n >> x >> y;
    for (int i = 1; i <= n + n; ++i) {
        dp[i] = dp[i - 1] + x;
        dp[i - 1] = min(dp[i - 1], dp[i] + x);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + y);
        else dp[i] = min(dp[i], dp[(i + 1) / 2] + x + y);
    }
    cout << dp[n] << endl;
}