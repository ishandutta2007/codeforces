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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= max(0, i - 500); j--) {
                if ((j ^ a[i]) > (i ^ a[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}