#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout.precision(6);
    long double hh, mm, h, d, c, n;
    cin >> hh >> mm >> h >> d >> c >> n;
    long double case1, case2;
    if (hh >= 20) {
        cout << fixed << ceil(h / n) * c * 0.8 << endl;
        return 0;
    }
    case1 = ceil(h / n) * c;
    long double t = 20 * 60 - (hh * 60 + mm);
    case2 = ceil((h + d * t) / n) * c * 0.8;
    cout << fixed << min(case1, case2) << endl;
    return 0;
}