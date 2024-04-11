#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int tst = 200;
const double inf = 1e9;
double a[maxn];
int n;

double cal(double x) {
    double s = 0.0;
    double mx = 0.0, mn = 0.0;
    double w = -100000000000;
    for (int i = 1; i <= n; ++i) {
        s += a[i] - x;
        w = max(w, max(abs(s - mx), abs(s - mn)));
        mx = max(mx, s);
        mn = min(mn, s);
    }
    return w;
}

double ts(double l, double r) {
    // cout << l << ' ' << r << endl;
    for (int i = 0; i < tst; ++i) {
        double m1 = l + (r - l) / 3, m2 = l + (r - l) / 3 * 2;
        if (cal(m1) < cal(m2)) r = m2;
        else l = m1;
    } 
    return l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    double x = ts(-inf, inf);
    cout << fixed << setprecision(20) << cal(x) << endl;
    return 0;
}