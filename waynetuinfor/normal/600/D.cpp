#include <bits/stdc++.h>
using namespace std;

using data = long double;

const data eps = 1e-9, pi = acos(-1);
data sq(data x) { return x * x; }
data dist(data x, data y, data a, data b) { return sqrt(sq(x - a) + sq(y - b)); }

int main() {
    data x1, y1, r1, x2, y2, r2; 
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r1 < r2) swap(x1, x2), swap(y1, y2), swap(r1, r2);
    data dcc = dist(x1, y1, x2, y2);
    if (fabs(r1 - r2) < eps && fabs(x1 - x2) < eps && fabs(y1 - y2) < eps) return cout << fixed << setprecision(20) << r1 * r1 * pi << endl, 0; 
    if (dcc > r1 + r2) return cout << fixed << setprecision(20) << 0.0 << endl, 0;
    if (fabs(dcc - r1 - r2) < eps) return cout << fixed << setprecision(20) << 0.0 << endl, 0;
    if (fabs(dcc - (r1 - r2)) < eps) return cout << fixed << setprecision(20) << r2 * r2 * pi << endl, 0;
    if (dcc < r1 - r2) return cout << fixed << setprecision(20) << r2 * r2 * pi << endl, 0;
    data a = r1, b = r2, c = dcc, d = (a + b + c) / 2.0;
    data s = sqrt(d * (d - a) * (d - b) * (d - c)), h = 2 * s / c;
    if (fabs(dcc - r1) < eps) {
        data bt = asin(h / b) * 2;
        data bs = r2 * r2 * pi * (bt / 2.0 / pi);
        data at = asin(h / a);
        data as = r1 * r1 * pi * (at / 2.0 / pi) - s;
        cout << fixed << setprecision(20) << bs + as + as << endl;
        return 0;
    }
    if (fabs(dcc - r2) < eps || dcc < r1) {
        data bt = asin(h / b) * 2;
        if (a * a - h * h > c * c) bt = 2 * pi - bt;
        data bs = r2 * r2 * pi * (bt / 2.0 / pi);
        data at = asin(h / a);
        data as = r1 * r1 * pi * (at / 2.0 / pi) - s;
        cout << fixed << setprecision(20) << bs + as + as << endl;
        return 0;
    }
    data bt = asin(h / b) * 2;
    data at = asin(h / a) * 2;
    data bs = r2 * r2 * pi * (bt / 2.0 / pi);
    data as = r1 * r1 * pi * (at / 2.0 / pi);
    cout << fixed << setprecision(20) << bs + as - s - s << endl;
    return 0;
}