#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const double eps = 1e-7;

int n, l, v1, v2, k;
bool check (double aim) {
    double t = (l - aim * v1) / (v2 - v1);
    int now = n; double s = l;
    while (now--) {
        if (t * v2 > s) return 0;
        if (!now) return 1;
        s -= t * v1 + ((t * (v2 - v1)) / (v1 + v2)) * v1;
        if (s < 0) return 0;
    }
    return 1;
}

int main () {
    n = read(), l = read(), v1 = read(), v2 = read(), k = read();
    n = (n / k) + bool(n % k);
    double L = 0, R = 1.0 * l / v1, ans = 1.0 * l / v1;
    while (L <= R - eps) {
        double mid = (L + R) / 2;
        if (check(mid)) ans = mid, R = mid - eps;
        else L = mid + eps;
    }
    printf("%.8lf\n", ans);
    return 0;
}