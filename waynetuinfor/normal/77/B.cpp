#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        long double p, q; cin >> p >> q;
        if (p == 0 && q == 0) { cout << 1.0000000000 << endl; continue; }
        if (p == 0) { cout << 0.500000000000 << endl; continue; }
        if (q == 0) { cout << 1.000000000000 << endl; continue; }
        long double y = p / 4.0;
        pair<long double, long double> pt;
        if (y >= -q && y <= q) pt = make_pair(p, y);
        long double x = 4 * q;
        if (x >= 0 && x <= p) pt = make_pair(x, q);
        x = -4 * q;
        if (x >= 0 && x <= p) pt = make_pair(x, -q);
        if (pt.first == p) {
            long double len = q - pt.second;
            cout << fixed << setprecision(20) << (p * 2 * q - (len + q) * p / 2.0) / (p * 2 * q) << endl;
        } else if (pt.second == q) {
            long double len = pt.first;
            cout << fixed << setprecision(20) << (p * 2 * q - q * len / 2) / (p * 2 * q) << endl; 
        } else {
            long double len = pt.first;
            cout << fixed << setprecision(20) << (q * len / 2) / (p * 2 * q) << endl;
        }
    }
    return 0;
}