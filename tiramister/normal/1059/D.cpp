#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
inline T sq(T a) { return a * a; }

const long double EPS = 1e-8;
const long double MAX = 6e13;

long double calc(long double y, long double R) {
    if (y > R * 2) return -MAX;
    return sqrtl(sq(R) - sq(y - R));
}

int main() {
    int N;
    cin >> N;
    long double x[N], y[N];
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
    if (*min_element(y, y + N) < 0 && *max_element(y, y + N) > 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; ++i) y[i] = abs(y[i]);

    long double ok = MAX, ng = 0;
    while (ok - ng > max(EPS, ok * EPS)) {
        long double R = (ok + ng) / 2;
        long double l = -MAX, r = MAX;

        for (int i = 0; i < N; ++i) {
            long double d = calc(y[i], R);
            l = max(l, x[i] - d);
            r = min(r, x[i] + d);
        }

        if (l < r) {
            ok = R;
        } else {
            ng = R;
        }
    }

    cout << fixed << setprecision(10) << ok << endl;
    return 0;
}