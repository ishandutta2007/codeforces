#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const double eps = 1e-9;
double xp[maxn], np[maxn];
double pa[maxn], pb[maxn], a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lf", &xp[i]);
    for (int i = 1; i <= n; ++i) scanf("%lf", &np[i]);
    pa[n] = pb[n] = 1.0;
    for (int i = n; i >= 1; --i) {
        double x = -(xp[i] + np[i] - pa[i] - pb[i]);
        double y = pa[i] * pb[i] - xp[i];
        double d = x * x - 4 * y;
        if (d < 0 && fabs(d) < eps) d = 0.0;
        double r1 = (x + sqrt(d)) / 2, r2 = (x - sqrt(d)) / 2;
        if (r1 >= 0 && r1 <= 1 && x - r1 >= 0 && x - r1 <= 1) {
            pb[i - 1] = r1;
            pa[i - 1] = x - r1;
        } else {
            pb[i - 1] = r2;
            pa[i - 1] = x - r2;
        }
        a[i] = pa[i] - pa[i - 1];
        b[i] = pb[i] - pb[i - 1];
    }
    for (int i = 1; i <= n; ++i) printf("%.20lf ", a[i]); puts("");
    for (int i = 1; i <= n; ++i) printf("%.20lf ", b[i]); puts("");
}