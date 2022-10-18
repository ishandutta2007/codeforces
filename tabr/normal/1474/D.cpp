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
        vector<int> x(n, -1), y(n, -1);
        x[0] = a[0];
        y[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) {
            x[i] = a[i] - x[i - 1];
            if (x[i] < 0) {
                x[i] = -1;
                break;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            y[i] = a[i] - y[i + 1];
            if (y[i] < 0) {
                y[i] = -1;
                break;
            }
        }
        if (x[n - 1] == 0) {
            cout << "YES" << '\n';
            continue;
        }
        string ans = "NO";
        for (int i = 0; i < n - 1; i++) {
            int l = (i == 0 ? 0 : x[i - 1]);
            int r = (i == n - 2 ? 0 : y[i + 2]);
            if (min(l, r) < 0) {
                continue;
            }
            if (a[i + 1] >= l && a[i] >= r && a[i + 1] - l == a[i] - r) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}