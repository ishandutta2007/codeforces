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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string t(n, '0');
        for (int i = 0; i < n; i++) {
            if (a[i] <= q) {
                t[i] = '1';
            }
        }
        int low = 0;
        int high = n + 1;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            string s = t;
            for (int i = 0; i < mid; i++) {
                s[n - 1 - i] = '1';
            }
            bool ok = true;
            int x = q;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    if (x < a[i]) {
                        x--;
                    }
                }
            }
            if (x < 0) {
                ok = false;
            }
            if (ok) {
                low = mid;
            } else {
                high = mid;
            }
        }
        for (int i = 0; i < low; i++) {
            t[n - 1 - i] = '1';
        }
        cout << t << '\n';
    }
    return 0;
}