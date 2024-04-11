#include <bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 1e5 + 10;
const double pi = acos(-1);
const double inf = 1e18;
pair<double, double> pt[maxn];

inline double dis(const pair<double, double>& a, const pair<double, double>& b) {
    return sqrt(
        (a.first - b.first) * (a.first - b.first) + \
        (a.second - b.second) * (a.second - b.second) \
    );
}

inline double len(const pair<double, double>& p) {
    return sqrt(p.first * p.first + p.second * p.second);
}

bool check(const pair<double, double>& a, const pair<double, double>& b, const pair<double, double>& c) {
    pair<double, double> p1 = make_pair(a.first - b.first, a.second - b.second), p2 = make_pair(c.first - b.first, c.second - b.second);
    if ((p1.first * p2.first + p1.second * p2.second) / len(p1) / len(p2) < 0) return false;
    p1 = make_pair(b.first - a.first, b.second - a.second), p2 = make_pair(c.first - a.first, c.second - a.second);
    if ((p1.first * p2.first + p1.second * p2.second) / len(p1) / len(p2) < 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    pair<double, double> p;
    int n; cin >> n >> p.first >> p.second;
    double mx = 0.0, mn = inf;
    for (int i = 0; i < n; ++i) {
        cin >> pt[i].first >> pt[i].second;
        mx = max(mx, dis(p, pt[i])); mn = min(mn, dis(p, pt[i]));
    }
    for (int i = 0; i < n; ++i) {
        double a = dis(pt[i % n], pt[(i + 1) % n]), b = dis(pt[(i + 1) % n], p), c = dis(pt[i % n], p);
        double s = (a + b + c) / 2.0;
        double ar = sqrt(s * (s - a) * (s - b) * (s - c));
        if (check(pt[i % n], pt[(i + 1) % n], p)) mn = min(mn, ar * 2 / a);
    }
    cout << fixed << setprecision(20) << pi * mx * mx - pi * mn * mn << endl;
    return 0;
}