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
    vector<int> dp(1001, 1001);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j <= i; j++) {
            int ni = i + i / j;
            if (ni <= 1000) {
                dp[ni] = min(dp[ni], dp[i] + 1);
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i] = dp[b[i]];
        }
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        k = min(k, 12 * n + 1);
        vector<int> f(k + 1, -1);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = k - b[i]; j >= 0; j--) {
                f[j + b[i]] = max(f[j + b[i]], f[j] + c[i]);
            }
        }
        cout << *max_element(f.begin(), f.end()) << '\n';
    }
    return 0;
}