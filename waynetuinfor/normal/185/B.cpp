#include <bits/stdc++.h>
using namespace std;

const int inf = 1e3 + 1;
const double eps = 1e-6;
double s, a, b, c;

double _log(double x) { return x == 0.0 ? 0.0 : log(x); }

double cal(double x, double y) {
    double z = s - x - y;
    assert(z >= 0);
    return a * _log(x) + b * _log(y) + c * _log(z);
}

double ts2(double x, double l, double r) {
    if (r - l < eps) return l;
    double lm = l + (r - l) / 3.0, rm = l + (r - l) / 3.0 * 2.0;
    if (cal(x, lm) >= cal(x, rm)) return ts2(x, l, rm);
    return ts2(x, lm, r);
}

bool check(double c, double d) {
    double cc = ts2(c, 0, s - c), dd = ts2(d, 0, s - d);
    return cal(c, cc) >= cal(d, dd);
}

double ts1(double l, double r) {
    if (r - l < eps) return l;
    double lm = l + (r - l) / 3.0, rm = l + (r - l) / 3.0 * 2.0;
    if (check(lm, rm)) return ts1(l, rm);
    return ts1(lm, r);
}

int main() {
    cin >> s >> a >> b >> c;
    double x = ts1(0, s), y = ts2(x, 0, s - x), z = s - x - y;
    cout << fixed << setprecision(20) << x << ' ' << y << ' ' << z << endl;
    return 0;
}