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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = -1;
        for (int i = 0, j = 0; i < n; i = j) {
            int mn = a[i];
            int mx = a[i];
            while (abs(mn - mx) <= 2 * x) {
                j++;
                if (j == n) {
                    break;
                }
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
            }
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}