#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
double x[maxn], y[maxn];

inline int sgn(double t) {
    return t > 0 ? 1 : -1;
}

int main() {
    int n; scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &x[i], &y[i]);
        s.insert(sgn(y[i]));
    }
    if (s.size() > 1) {
        puts("-1");
        return 0;
    }
    if (*s.begin() == -1) {
        for (int i = 0; i < n; ++i) y[i] *= -1;
    }
    double l = -1e7 - 1, r = 1e7 + 1;
    function<double(double)> check = [&](double t) {
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            double a = (t - x[i]) * (t - x[i]);
            res = max(res, (y[i] * y[i] + a) / (2 * y[i]));
        }
        return res;
    };
    int iter = 400;
    while (iter--) {
        double ml = l + (r - l) / 3, mr = r - (r - l) / 3;
        double yl = check(ml), yr = check(mr);
        if (yl > yr) l = ml;
        else r = mr;
    }
    printf("%.20lf\n", check(l));
}