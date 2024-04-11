#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]); cout << ans << endl;
    return 0;
}