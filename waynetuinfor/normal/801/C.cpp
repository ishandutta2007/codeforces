#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
double p;
int n;

struct T {
    double a, b;
    bool operator>(const T& t) const {
        return a / b > t.a / t.b;
    }
} t[maxn];

double bs(double, double);
bool check(double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> p;
    for (int i = 0; i < n; ++i) cin >> t[i].a >> t[i].b;
    double ans = bs(0, 1e14 + 2);
    if (ans > 1e14) cout << "-1\n";
    else cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}

double bs(double l, double r) {
    if (r - l < 1e-5) return l;
    double m = (l + r) / 2;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

bool check(double tt) {
    double chk = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = max(0.0, tt * t[i].a - t[i].b);
        chk += x / tt;
    }
    return chk <= p;
}