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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (i - b[i] >= 0 && dp[i - b[i]]) {
                dp[i + 1] = true;
            }
            if (i + b[i] + 1 <= n && dp[i]) {
                dp[i + b[i] + 1] = true;
            }
        }
        debug(dp);
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}