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
        vector<int> c;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= 2;
            if (a[i]) {
                c.emplace_back(i);
            }
        }
        long long inf = (int) 1e18;
        long long ans = inf;
        for (int _ = 0; _ < 2; _++) {
            vector<int> b;
            for (int i = 0; i < n; i++) {
                if (i % 2 == _) {
                    b.emplace_back(i);
                }
            }
            long long t = 0;
            if (b.size() != c.size()) {
                continue;
            }
            for (int i = 0; i < (int) b.size(); i++) {
                t += abs(b[i] - c[i]);
            }
            ans = min(ans, t);
        }
        if (ans == inf) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}