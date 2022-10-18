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
        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans += (a[i] + 1) / 2;
        }
        int ok = 0;
        int mx = 1;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] % 2 == 0) {
                ok = 1;
            }
            mx = max(mx, a[i]);
        }
        if (n > 3 && mx >= 3) {
            ok = 1;
        }
        if (!ok) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}