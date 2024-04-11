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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<int, int> b;
        for (int i = 0; i < n; i++) {
            b[a[i]]++;
        }
        map<int, int> cnt;
        for (auto [x, y] : b) {
            cnt[y]++;
        }
        int ans = (int) 1e9;
        int need = 0;
        for (int m = 0; m <= n; m++) {
            int d = 0;
            int t = k;
            for (auto [x, y] : cnt) {
                int s = min(y, t / x);
                d += y - s;
                t -= s * x;
            }
            ans = min(ans, d);
            if (!b.count(m)) {
                need++;
            } else {
                cnt[b[m]]--;
            }
            if (need > k) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}