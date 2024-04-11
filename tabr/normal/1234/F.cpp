#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(1 << 20);
    // set<int> q;
    for (int i = 0; i < n; i++) {
        int st = 0;
        for (int j = i; j < n; j++) {
            if (st & (1 << (s[j] - 'a'))) {
                break;
            } else {
                st |= 1 << (s[j] - 'a');
            }
            // q.emplace(st);
            dp[st] = __builtin_popcount(st);
        }
    }
    debug(q);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 20); j++) {
            if (j & (1 << i)) {
                dp[j] = max(dp[j], dp[j ^ (1 << i)]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        ans = max(ans, dp[i] + dp[(1 << 20) - 1 - i]);
    }
    cout << ans << '\n';
    return 0;
}