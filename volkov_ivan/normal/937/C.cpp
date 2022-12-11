#include <iostream>
#include <cmath>

using namespace std;

long double eps = 1e-10;

int main()  {
    cout.precision(12);
    long double k, d, t;
    cin >> k >> d >> t;
    long double num = ceil(k / d);
    //k = num * (d - 1) + k;
    d *= num;
    //cout << fixed << num << ' ' << k << ' ' << d << endl;
    long double v_on = 1.0 / t, v_off = v_on / 2;
    long double part = v_on * k + v_off * (d - k);
    //cout << part << endl;
    long double l = 0.0, r = 2e18 * 1.1, m, now, rest;
    int cnt = 0;
    while (cnt < 10000) {
        m = (l + r) / 2;
        //cout << fixed << m << endl;
        now = (v_on * k + v_off * (d - k)) * floor(m / d);
        rest = m - floor(m / d) * d;
        now += v_on * min(k, rest);
        if (rest > k) {
            now += v_off * (rest - k);
        }
        if (now >= 1) {
            r = m;
        } else {
            l = m;
        }
        cnt++;
    }
    cout << fixed << r << endl;
    return 0;
}