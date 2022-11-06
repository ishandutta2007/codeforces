#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const double eps = 1e-9;
int n; 
double ti[maxn], vs, vp;

struct point {
    double x, y, z;
    point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
    point operator+(const point &p) const { return point(x + p.x, y + p.y, z + p.z); }
    point operator-(const point &p) const { return point(x - p.x, y - p.y, z - p.z); }
    point operator*(double r) const { return point(r * x, r * y, r * z); }
    double operator()() const { return sqrt(x *  x + y * y + z * z); }
} p[maxn], s, f;

bool check(double t) {
    // cout << "check t = " << t << endl;
    double c = 0.0;
    for (int i = 1; i <= n; ++i) {
        if (c + ti[i] > t || fabs(t - c - ti[i]) < eps) {
            // cout << "hey i = " << i << endl;
            double r = (t - c) / ti[i];
            // cout << "r = " << r << endl;
            point d = p[i - 1] + (p[i] - p[i - 1]) * r;
            // cout << "d - s = " << (d - s).x << ' ' << (d - s).y << ' ' << (d - s).z << endl;
            // cout << "need = " << (d - s)() / vp << endl;
            if ((d - s)() / vp <= t) {
                // cout << "f = " << f.x << ' ' << f.y << ' ' << f.z << endl;
                f = d;
                return true;
            } 
            return false;
        }
        c += ti[i];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(20);
    cin >> n;
    for (int i = 0; i <= n; ++i) cin >> p[i].x >> p[i].y >> p[i].z;
    cin >> vp >> vs;
    cin >> s.x >> s.y >> s.z;
    double all = 0.0;
    for (int i = 1; i <= n; ++i) {
        double k = (p[i] - p[i - 1])();
        ti[i] = k / vs;
        all += ti[i];
    }
    if ((p[n] - s)() / vp > all + eps) {
        cout << "NO" << endl;
        return 0;
    }
    double l = 0.0, r = all + eps;
    // cout << "r = " << r << endl;
    for (int i = 0; i < 200; ++i) {
        double m = (l + r) / 2.0;
        if (check(m)) r = m;
        else l = m;
    }
    cout << "YES" << endl;
    cout << l << endl;
    cout << f.x << ' ' << f.y << ' ' << f.z << endl;
}