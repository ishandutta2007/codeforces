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
    cout << fixed << setprecision(12);
    while (tt--) {
        double x, y, z, v;
        cin >> x >> y >> z >> v;
        double eps = 1e-9;
        auto f = [&](auto &&self, double a, double b) -> double {
            double res = 1;
            // debug(a, b);
            if (a > v) {
                if (b > eps) {
                    res += a * self(self, a - v, b + v / 2);
                } else {
                    res += a * self(self, a - v, 0);
                }
            } else if (a > eps && b > eps) {
                res += a * self(self, 0, b + a / 2);
            } else {
                res += a;
            }
            if (b > v) {
                if (a > eps) {
                    res += b * self(self, a + v / 2, b - v);
                } else {
                    res += b * self(self, 0, b - v);
                }
            } else if (a > eps && b > eps) {
                res += b * self(self, a + b / 2, 0);
            } else {
                res += b;
            }
            return res;
        };
        cout << f(f, x, y) << '\n';
    }
    return 0;
}