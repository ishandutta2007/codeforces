#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> cnt(n);
    vector<int> last(n, -1);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = cnt[a[i]];
        cnt[a[i]]++;
        last[a[i]] = i;
    }
    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            dp[last[a[i]] + 1] = min(dp[last[a[i]] + 1], dp[i] + last[a[i]] - i + 1 - cnt[a[i]]);
        }
        dp[n] = min(dp[n], dp[i] + n - i - cnt[a[i]] + b[i]);
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}