#include <bits/stdc++.h>
using namespace std;

const double inf = 1e9 + 1, eps = 1e-7;
pair<double, double> st, ed, v, w;
double vmax, t;

double len(const pair<double, double>& p) {
    return sqrt(p.first * p.first + p.second * p.second);
}

bool check(double ti) {
    double x = st.first, y = st.second;
    x += v.first * min(ti, t); y += v.second * min(ti, t);
    x += w.first * max(ti - t, 0.0); y += w.second * max(ti - t, 0.0);
    pair<double, double> dir = make_pair(ed.first - x, ed.second - y);
    return len(dir) <= ti * vmax;
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2.0;
    if (check(m)) return bs(l, m);
    return bs(m, r);
} 

int main() {
    cin >> st.first >> st.second >> ed.first >> ed.second;
    cin >> vmax >> t;
    cin >> v.first >> v.second >> w.first >> w.second;
    cout << fixed << setprecision(20) << bs(0, inf);
    return 0;
}