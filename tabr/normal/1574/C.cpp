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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long s = accumulate(a.begin(), a.end(), 0LL);
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while (m--) {
        long long x, y;
        cin >> x >> y;
        int id = (int) (lower_bound(a.begin(), a.end(), x) - a.begin());
        if (id == n) {
            long long ans = x - a.back();
            long long t = s - a.back();
            ans += max(0LL, y - t);
            cout << ans << '\n';
        } else {
            long long t = s - a[id];
            if (t >= y) {
                cout << 0 << '\n';
            } else if (id == 0) {
                cout << max(0LL, y - t) << '\n';
            } else {
                cout << min(y - t, (x - a[id - 1]) + max(0LL, y - (s - a[id - 1]))) << '\n';
            }
        }
    }
    return 0;
}