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
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) {
                a.emplace_back(abs(y));
            } else {
                b.emplace_back(abs(x));
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]);
        }
        cout << fixed << setprecision(15);
        cout << ans << '\n';
    }
    return 0;
}