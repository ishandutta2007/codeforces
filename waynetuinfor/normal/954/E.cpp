#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const double eps = 1e-9;
pair<int, int> p[maxn];

int main() {
    int n, t; scanf("%d %d", &n, &t);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i].second);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i].first);
    for (int i = 0; i < n; ++i) p[i].first -= t;
    sort(p, p + n, [](const pair<int, int> &a, const pair<int, int> &b) { return abs(a.first) < abs(b.first); });
    double a = 0.0, b = 0.0, c = 0.0;
    for (int i = 0; i < n; ++i) if (p[i].first < 0) a += p[i].second * 1.0 * (-p[i].first);
    for (int i = 0; i < n; ++i) if (p[i].first > 0) b += p[i].second * 1.0 * (+p[i].first);
    for (int i = 0; i < n; ++i) if (p[i].first == 0) c += p[i].second;
    a = min(a, b);
    double r = a;
    for (int i = 0; i < n; ++i) if (p[i].first < 0) {
        double z = min(1.0 * p[i].second, r / -p[i].first);
        c += z; r -= (-p[i].first) * 1.0 * z;
        if (r < eps) break;
    }
    r = a;
    for (int i = 0; i < n; ++i) if (p[i].first > 0) {
        double z = min(1.0 * p[i].second, r / p[i].first);
        c += z; r -= (+p[i].first) * 1.0 * z;
        if (r < eps) break;
    }
    printf("%.20lf\n", c);
    return 0;
}