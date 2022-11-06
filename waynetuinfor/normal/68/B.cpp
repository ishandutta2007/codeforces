#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10, maxv = 1500;
const double eps = 1e-6;
double a[maxn], b[maxn], per;
bool v[maxn];
int n;

bool check(double t) {
    int r = n - 1;
    for (int i = 0; i < n; ++i) b[i] = a[i];
    for (int i = 0; i < r; ++i) {
        if (b[i] >= t) return true;
        double nd = (t - b[i]) / per;
        while (r > i) {
            if (b[r] < t) return false;
            double g = min(nd, b[r] - t);
            b[r] -= g; nd -= g;
            if (b[r] == t) --r;
            if (nd < eps) break;
        }
        if (nd > eps) return false;
    }
    return true;
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> n >> k;
    double ub = 0.0;
    for (int i = 0; i < n; ++i) cin >> a[i], ub = max(ub, a[i]);
    sort(a, a + n); 
    per = 1.0 - ((double)k / 100.0);
    cout << fixed << setprecision(20) << bs(0, ub) << endl;
    return 0;
}