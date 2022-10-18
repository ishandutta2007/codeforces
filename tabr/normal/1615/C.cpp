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
        string a, b;
        cin >> a >> b;
        int x = (int) (count(a.begin(), a.end(), '0'));
        int y = (int) (count(b.begin(), b.end(), '0'));
        if (x != y && n - x - 1 != y) {
            cout << -1 << '\n';
            continue;
        }
        int inf = (int) 1e9;
        int ans = inf;
        if (x == y) {  // even flip
            int zero = 0;
            int one = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    if (a[i] == '0') {
                        zero++;
                    } else {
                        one++;
                    }
                }
            }
            if (zero == one) {
                ans = min(ans, zero + one);
            }
        }
        if (n - 1 - x == y) {  // odd flip
            for (int i = 0; i < n; i++) {
                b[i] ^= '0' ^ '1';
            }
            int zero = 0;
            int one = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    if (a[i] == '0') {
                        zero++;
                    } else {
                        one++;
                    }
                }
            }
            if (zero + 1 == one) {
                ans = min(ans, zero + one);
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}