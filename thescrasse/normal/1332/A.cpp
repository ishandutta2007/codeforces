#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, c, d, x, y, xl, xr, yl, yr, d1, d2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> xl >> yl >> xr >> yr;
        d1 = b - a;
        d2 = d - c;
        if (d1 == 0) {
            if (a != 0 && xl == x && x == xr) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (d1 > 0) {
            if (xr - x < d1) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (d1 < 0) {
            if (x - xl < (-d1)) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (d2 == 0) {
            if (c != 0 && yl == y && y == yr) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (d2 > 0) {
            if (yr - y < d2) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (d2 < 0) {
            if (y - yl < (-d2)) {
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
    }

    return 0;
}