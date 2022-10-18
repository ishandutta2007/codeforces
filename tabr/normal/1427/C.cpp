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
    int r, n;
    cin >> r >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    vector<int> dp(n + 1, -1e9);
    vector<int> s(n + 1, -1e9);
    dp[0] = 0;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--, y[i]--;
        for (int j = i - 1; j >= 0; j--) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[j] <= t[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (t[j] + r * 2 <= t[i]) {
                dp[i] = max(dp[i], s[j] + 1);
                break;
            }
        }
        s[i] = max(s[i - 1], dp[i]);
    }
    cout << s[n] << '\n';
    return 0;
}