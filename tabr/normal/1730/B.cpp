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
        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        vector<int> a(2 * n);
        for (int i = 0; i < n; i++) {
            a[i + n] = x[i] + t[i];
            a[i] = x[i] - t[i];
        }
        sort(a.begin(), a.end());
        cout << fixed << setprecision(12);
        cout << (a[2 * n - 1] + a[0]) * 0.5 << '\n';
    }
    return 0;
}