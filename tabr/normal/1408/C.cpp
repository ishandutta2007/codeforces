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
    cout << fixed << setprecision(10);
    while (tt--) {
        int n;
        cin >> n;
        double l;
        cin >> l;
        vector<double> a(n + 2);
        for (int i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        a[n + 1] = l;
        vector<double> x(n + 2), y(n + 2);
        for (int i = 1; i <= n + 1; i++) {
            x[i] = x[i - 1] + (a[i] - a[i - 1]) / i;
        }
        for (int i = n; i >= 0; i--) {
            y[i] = y[i + 1] + (a[i + 1] - a[i]) / (n + 1 - i);
        }
        for (int i = 1; i <= n + 1; i++) {
            if (x[i] > y[i]) {
                double t = (x[i - 1] * i + y[i] * (n + 2 - i) + a[i] - a[i - 1]) / (n + 2);
                cout << t << '\n';
                break;
            }
        }
    }
    return 0;
}