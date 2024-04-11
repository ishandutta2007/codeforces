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
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<long long> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (t[i] != t[j]) {
                    long long old = dp[i];
                    dp[i] = max(dp[i], dp[j] + abs(s[i] - s[j]));
                    dp[j] = max(dp[j], old + abs(s[i] - s[j]));
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}