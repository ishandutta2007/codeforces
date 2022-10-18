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
        if (n % 2 == 1) {
            long long ans = 0;
            for (int i = 1; i < n; i += 2) {
                int add = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0);
                ans += add;
            }
            cout << ans << '\n';
        } else {
            const long long inf = (long long) 1e18;
            vector<long long> b(n, inf);
            for (int i = 1; i < n - 1; i += 2) {
                int add = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0);
                b[i] = (i == 1 ? 0 : b[i - 2]) + add;
            }
            vector<long long> c(n, inf);
            for (int i = n - 2; i > 0; i -= 2) {
                int add = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0);
                c[i] = (i == n - 2 ? 0 : c[i + 2]) + add;
            }
            long long ans = min(b[n - 3], c[2]);
            for (int i = 1; i + 3 < n; i += 2) {
                ans = min(ans, b[i] + c[i + 3]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}