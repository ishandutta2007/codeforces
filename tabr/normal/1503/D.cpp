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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> c(2 * n);
    vector<int> d(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        c[a[i]] = b[i];
        c[b[i]] = a[i];
        d[b[i]] = 1;
    }
    int ans = 0;
    vector<int> z(2 * n);
    int lo = 0, hi = 2 * n - 1;
    while (lo < hi) {
        if (z[lo]) {
            lo++;
            continue;
        }
        if (z[hi]) {
            hi--;
            continue;
        }
        if (c[lo] == hi) {
            z[lo] = z[hi] = 1;
            lo++, hi--;
            continue;
        }
        int x = c[lo];
        int y = c[hi];
        if (y > x) {
            cout << -1 << '\n';
            return 0;
        }
        z[lo] = z[hi] = z[x] = z[y] = 1;
        int add = d[lo] + d[hi];
        int cnt = 2;
        while (lo < hi && (lo + 1 < y || hi - 1 > x)) {
            if (lo + 1 < y) {
                lo++;
                debug(lo, y, x);
                if (z[lo]) {
                    continue;
                }
                if (c[lo] > x) {
                    cout << -1 << '\n';
                    return 0;
                }
                x = c[lo];
                z[lo] = z[c[lo]] = 1;
                cnt++;
                add += d[lo];
            } else {
                hi--;
                debug(hi, y, x);
                if (z[hi]) {
                    continue;
                }
                if (c[hi] < y) {
                    cout << -1 << '\n';
                    return 0;
                }
                y = c[hi];
                z[hi] = z[c[hi]] = 1;
                cnt++;
                add += d[hi];
            }
            if (y > x) {
                cout << -1 << '\n';
                return 0;
            }
        }
        ans += min(add, cnt - add);
    }
    cout << ans << '\n';
    return 0;
}