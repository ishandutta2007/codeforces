#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int r, x, y, xp, yp; cin >> r >> x >> y >> xp >> yp;
    double d = dist(x, y, xp, yp);
    r *= 2;
    cout << (int)ceil(d / r) << endl;
    return 0;
}