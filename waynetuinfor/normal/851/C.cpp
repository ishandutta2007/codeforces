#include <bits/stdc++.h>
#define double long double
using namespace std;

const double pi = acos(-1);

struct pt {
    double a, b, c, d, e;
    pt() {}
    pt(double a, double b, double c, double d, double e): a(a), b(b), c(c), d(d), e(e) {}
    pt operator+(const pt& p) const {
        return pt(a + p.a, b + p.b, c + p.c, d + p.d, e + p.e);
    }
    pt operator-(const pt& p) const {
        return pt(a - p.a, b - p.b, c - p.c, d - p.d, e - p.e);
    }
    double operator*(const pt& p) const {
        return a * p.a + b * p.b + c * p.c + d * p.d + e * p.e;
    }
};

double angle(const pt& a, const pt& b) {
    return acos(a * b / sqrt(a * a) / sqrt(b * b));
}

const int maxn = 1e3 + 10;
int main() {
    int n; cin >> n;
    vector<pt> p(n);
    set<int> ind;
    bitset<maxn> bd;
    for (int i = 0; i < n; ++i) cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d >> p[i].e;
    for (int i = 0; i < n; ++i) {
        bool done = false;
        for (int j = 0; j < n && !done; ++j) if (i != j) {
            for (int k = 0; k < n && !done; ++k) if (k != i && k != j) {
                double ang = angle(p[i] - p[j], p[i] - p[k]);
                if (ang < pi * .5 || ang > 1.5 * pi) bd[i] = true, done = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) if (!bd[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << endl;
    return 0;
}