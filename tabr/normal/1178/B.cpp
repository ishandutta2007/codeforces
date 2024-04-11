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
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<long long> dp(3);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i] && s[i] == 'v') {
            dp[0]++;
            dp[2] += dp[1];
        } else if (s[i] == 'o') {
            dp[1] += dp[0];
        }
    }
    cout << dp[2] << '\n';
    return 0;
}