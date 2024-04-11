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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(2 * n);
        int j = 0;
        vector<int> c;
        for (int i = 0; i < 2 * n; i++) {
            cin >> p[i];
            if (p[j] < p[i]) {
                c.emplace_back(i - j);
                j = i;
            }
        }
        c.emplace_back(2 * n - j);
        debug(c);
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i : c) {
            for (int j = n - 1; j >= 0; j--) {
                if (dp[j] && i + j <= n) {
                    dp[i + j] = true;
                }
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}