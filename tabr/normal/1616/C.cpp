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
        if (n <= 2) {
            cout << 0 << '\n';
            continue;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto b = a;
                int d = b[j] - b[i];
                for (int k = 0; k < n; k++) {
                    b[k] *= j - i;
                }
                int t = 0;
                for (int k = 0; k < n; k++) {
                    if (b[k] != d * (k - i) + b[i]) {
                        t++;
                    }
                }
                ans = min(t, ans);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}