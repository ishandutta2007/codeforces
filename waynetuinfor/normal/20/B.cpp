#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c; cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) cout << "-1" << endl;
            else cout << "0" << endl;
            return 0;
        }
        cout << "1" << endl;
        cout << fixed << setprecision(20) << -c / b << endl;
        return 0;
    } 
    if (d < 0.0) return cout << "0" << endl, 0;
    if (d == 0.0) {
        cout << "1" << endl;
        cout << fixed << setprecision(20) << -1 * b / a / 2.0 << endl;
        return 0;
    }
    double k = sqrt(d);
    cout << "2" << endl;
    if (a > 0.0) {
        cout << fixed << setprecision(20) << (-b - k) / (2 * a) << endl;
        cout << fixed << setprecision(20) << (-b + k) / (2 * a) << endl;
    } else {
        cout << fixed << setprecision(20) << (-b + k) / (2 * a) << endl;
        cout << fixed << setprecision(20) << (-b - k) / (2 * a) << endl;
    }
    return 0;
}