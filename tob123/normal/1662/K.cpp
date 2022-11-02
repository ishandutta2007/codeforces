#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
#define double long double
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const double pi = acos(-1);
typedef pair<double, double> pt;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  auto ccw = [&](pt a, pt b) {
    double x = a.st * b.nd - a.nd * b.st;
    return x < 0 ? -1 : (x > 0 ? 1 : 0);
  };
  auto dist = [&](pt a, pt b) {
    return hypot(a.st - b.st, a.nd - b.nd);
  };
  auto angle = [&](pt a, pt b, pt c) {
    a.st -= b.st;
    a.nd -= b.nd;
    c.st -= b.st;
    c.nd -= b.nd;
    double x = (a.st * c.st + a.nd * c.nd) / (hypot(a.st, a.nd) * hypot(c.st, c.nd));
    // cout << acos(x) << endl;
    // cout << a.st << " " << a.nd;
    // cout << c.st << " " << c.nd << endl;
    return acos(x);
  };

  auto fermat = [&](pt a, pt b, pt c) {
    int o = ccw(pt(b.st - a.st, b.nd - a.nd), pt(c.st - a.st, c.nd - a.nd));
    if (o == 0)
      return max({dist(a, b), dist(a, c), dist(b, c)});
    if (angle(a, b, c) >= 2 * pi / 3.)
      return dist(a, b) + dist(c, b);
    if (angle(b, c, a) >= 2 * pi / 3.)
      return dist(a, c) + dist(b, c);
    if (angle(c, a, b) >= 2 * pi / 3.)
      return dist(b, a) + dist(c, a);
    pt x = {(a.st + b.st) / 2., (a.nd + b.nd) / 2.};
    pt d = {b.st - a.st, b.nd - a.nd};
    d = {-d.nd, d.st};
    double l = hypot(d.st, d.nd);
    d.st /= l;
    d.nd /= l;
    l = dist(a, b) * sqrt(3.) / 2;
    if (o > 0)
      l = -l;
    d = {l * d.st + x.st, l * d.nd + x.nd};
    // cout << d.st << " " << d.nd << endl;
    return dist(c, d);
  };

  pair<int, int> a, b, c;
  cin >> a.st >> a.nd;
  cin >> b.st >> b.nd;
  cin >> c.st >> c.nd;

  auto eval = [&](double x, double y) {
    pt p = {x, y};
    // cout << fermat(p, a, c) << endl;
    // exit(0);
    return max({fermat(p, a, b), fermat(p, a, c), fermat(p, b, c)});
  };

  auto calc = [&](double x) {
    double lo = -1e4, hi = 1e4;
    for (int it = 0; it < 100; it++) {
      double m1 = (2 * lo + hi) / 3.;
      double m2 = (lo + 2 * hi) / 3.;
      double f1 = eval(x, m1);
      double f2 = eval(x, m2);
      if (f1 < f2)
        hi = m2;
      else
        lo = m1;
    }
    // cout << lo << endl;
    return eval(x, lo);
  };

  double lo = -1e4, hi = 1e4;
  for (int it = 0; it < 100; it++) {
    double m1 = (2 * lo + hi) / 3.;
    double m2 = (lo + 2 * hi) / 3.;
    double f1 = calc(m1);
    double f2 = calc(m2);
    if (f1 < f2)
      hi = m2;
    else
      lo = m1;
  }

  // a = {0, 0};
  // b = {0, 1};
  // c = {1, 0};
  // cout << fermat(a, b, c) << endl;
  // cout << fermat(b, c, a) << endl;
  // cout << fermat(c, a, b) << endl;
  // cout << fermat(b, a, c) << endl;
  // cout << fermat(a, c, b) << endl;
  // cout << fermat(c, b, a) << endl;
  // lo = 2.3842;
  cout << fixed << setprecision(10) << calc(lo) << endl;
}