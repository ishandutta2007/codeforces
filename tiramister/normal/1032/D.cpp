#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename T>
inline T sq(T a) { return a * a; }

double dist(double tx, double ty, double fx, double fy) {
    return sqrt(sq(tx - fx) + sq(ty - fy));
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double x[2], y[2];
    for (int i = 0; i < 2; ++i) {
        cin >> x[i] >> y[i];
    }

    double tx[2][2], ty[2][2];
    for (int i = 0; i < 2; ++i) {
        tx[i][0] = x[i];
        ty[i][0] = -(a * x[i] + c) / b;

        tx[i][1] = -(b * y[i] + c) / a;
        ty[i][1] = y[i];
    }

    double ans = abs(x[1] - x[0]) + abs(y[1] - y[0]);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = min(ans, dist(tx[0][i], ty[0][i], x[0], y[0]) + dist(tx[1][j], ty[1][j], tx[0][i], ty[0][i]) + dist(x[1], y[1], tx[1][j], ty[1][j]));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}