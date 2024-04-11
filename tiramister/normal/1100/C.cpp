#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double PI = acos(-1);

int main() {
    double N, r;
    cin >> N >> r;

    double ang = PI / N;

    double ok = 1e30, ng = 0;
    for (int i = 0; i < 200; ++i) {
        double mid = (ok + ng) / 2;

        if (sin(ang) * (r + mid) < mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << fixed << setprecision(10) << ok << endl;
    return 0;
}