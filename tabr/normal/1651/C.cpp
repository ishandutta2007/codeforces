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
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        long long ans = (long long) 1e18;
        for (int z = 0; z < 2; z++) {
            long long a0 = (long long) 1e18;
            long long a1 = (long long) 1e18;
            long long b0 = (long long) 1e18;
            long long b1 = (long long) 1e18;
            for (int i = 0; i < n; i++) {
                a0 = min(a0, abs(a[0] - b[i]));
                a1 = min(a1, abs(a[n - 1] - b[i]));
                b0 = min(b0, abs(b[0] - a[i]));
                b1 = min(b1, abs(b[n - 1] - a[i]));
            }
            long long x = min(abs(a[0] - b[0]), a0 + b0);
            long long y = min(abs(a[n - 1] - b[n - 1]), a1 + b1);
            ans = min(ans, x + y);
            reverse(b.begin(), b.end());
        }
        cout << ans << '\n';
    }
    return 0;
}