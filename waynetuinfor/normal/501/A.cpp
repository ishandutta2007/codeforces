#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

int main() {
    double a, b, c, d; cin >> a >> b >> c >> d;
    double p1 = max(3 * a / 10, a - a / 250 * c);
    double p2 = max(3 * b / 10, b - b / 250 * d);
    if (fabs(p1 - p2) < eps) cout << "Tie" << endl;
    else if (p1 > p2) cout << "Misha" << endl;
    else cout << "Vasya" << endl;
    return 0;
}