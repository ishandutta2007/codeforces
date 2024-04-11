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
        int ans = (int) 1e9;
        if (a.back() < k) {
            ans = 0;
        }
        for (int i = 3000; i >= max(1, a.back() / k); i--) {
            int mn = i;
            for (int x : a) {
                int t = x / (i + 1) + 1;
                // debug(i, x, t, k);
                assert(t <= k);
                t = min(t, k);
                assert(x / t <= i);
                mn = min(mn, x / t);
            }
            ans = min(ans, i - mn);
        }
        cout << ans << '\n';
    }
    return 0;
}