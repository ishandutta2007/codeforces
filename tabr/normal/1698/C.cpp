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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n <= 5) {
            string ans = "YES";
            for (int mask = 0; mask < (1 << n); mask++) {
                if (__builtin_popcount(mask) != 3) {
                    continue;
                }
                long long t = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        t += a[i];
                    }
                }
                if (!count(a.begin(), a.end(), t)) {
                    ans = "NO";
                }
            }
            cout << ans << '\n';
            continue;
        }
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                pos++;
            }
            if (a[i] < 0) {
                neg++;
            }
        }
        sort(a.begin(), a.end());
        if (max(pos, neg) > 1) {
            cout << "NO" << '\n';
        } else if (min(pos, neg) != 1) {
            cout << "YES" << '\n';
        } else if (a[0] + a[n - 1] != 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}