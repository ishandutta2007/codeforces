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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < l; i++) {
            int c;
            cin >> c;
            c--;
            x[c]++;
        }
        for (int i = 0; i < r; i++) {
            int c;
            cin >> c;
            c--;
            y[c]++;
        }
        vector<int> s, t;
        for (int i = 0; i < n; i++) {
            int a = min(x[i], y[i]);
            x[i] -= a;
            y[i] -= a;
            if (x[i]) {
                s.emplace_back(x[i]);
            }
            if (y[i]) {
                t.emplace_back(y[i]);
            }
        }
        if (accumulate(s.begin(), s.end(), 0) < accumulate(t.begin(), t.end(), 0)) {
            swap(s, t);
        }
        int p = accumulate(s.begin(), s.end(), 0);
        int q = accumulate(t.begin(), t.end(), 0);
        int k = (p - q) / 2;
        int ans = q;
        for (int i = 0; i < (int)s.size(); i++) {
            while (k > 0 && s[i] > 1) {
                ans++;
                k--;
                s[i] -= 2;
            }
        }
        if (k > 0) {
            ans += k * 2;
        }
        cout << ans << '\n';
    }
    return 0;
}