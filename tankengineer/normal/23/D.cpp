//23D
#include<cstdio>
#include<complex>
#include<cstring>

using namespace std;

const double eps = 1e-7;

#define point complex<double>

point a, b, c;
int t;

inline double det(point a, point b) {return a.real() * b.imag() - a.imag() * b.real(); }

bool solve(point k, point l, point m) {
    point mp = point(2 * l.real() - m.real(), 2 * l.imag() - m.imag());
    double a1 = mp.real() - k.real(), b1 = mp.imag() - k.imag(), c1 = - (mp.real() * mp.real() - k.real() * k.real() + mp.imag() * mp.imag() - k.imag() * k.imag()) / 2,
           a2 = mp.real() - l.real(), b2 = mp.imag() - l.imag(), c2 = - (mp.real() * mp.real() - l.real() * l.real() + mp.imag() * mp.imag() - l.imag() * l.imag()) / 2;
    point b = point((c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2), (c2 * a1 - c1 * a2) / (a2 * b1 - a1 * b2)), a = k * 2.0 - b, c = l * 2.0 - b, d = m * 2.0 - c;
  if (det(c - d, b - c) < eps || det(b - c, a - b) < eps || det(a - b, d - a) < eps || det(d - a, c - d) < eps) return false;
    printf("YES\n%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", a.real(), a.imag(), b.real(), b.imag(), c.real(), c.imag(), d.real(), d.imag());
    return true;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf %lf %lf", &a.real(), &a.imag(), &b.real(), &b.imag(), &c.real(), &c.imag());
        if (fabs(det(a - c, b - c)) < eps || !solve(c, a, b) && !solve(c, b, a) && !solve(b, a, c) && !solve(b, c, a) && !solve(a, b, c) && !solve(a, c, b)) puts("NO\n");
    }
    return 0;
}