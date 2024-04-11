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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        if (k > n) {
            ans = pref[n];
            for (int i = 0; i < n; i++) {
                ans += k - i - 1;
            }
        } else {
            for (int i = 0; i + k <= n; i++) {
                ans = max(ans, pref[i + k] - pref[i]);
            }
            for (int i = 0; i < k; i++) {
                ans += i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}