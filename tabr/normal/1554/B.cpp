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
        long long ans = (long long) -1e18;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                long long t = 1LL * (i + 1) * (j + 1);
                if (t <= ans) {
                    break;
                }
                ans = max(ans, t - k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}