//8D
#include<cstdio>
#include<cmath>
#include<complex>
#include<algorithm>

using namespace std;

#define point complex<double>

const double eps = 1e-7;

double t1, t2;
point c, s, h;

void readpoint(point &p) {
  double x, y;
  scanf("%lf %lf", &x, &y);
  p = point(x, y);
}

bool inter(point a, double r_a, point b, double r_b, point c, double r_c) { //ca b 
  if (abs(c - a) <= r_a && abs(c - b) <= r_b) return true;
  b -= a; c -= a; //a 
  point r = point(b.real() / abs(b), b.imag() / abs(b)); //xb
  b /= r; c /= r;
  double d = (r_a * r_a - r_b * r_b + abs(b) * abs(b)) / (2 * abs(b));
  double h = sqrt(max(r_a * r_a - d * d, 0.0));
  if (abs(h * h + (d - abs(b)) * (d - abs(b))) - r_b * r_b > eps) return false;
  if (abs(point(d, h) - c) <= r_c || abs(point(d, -h) - c) <= r_c) return true;
  return false;
}

bool check(point a, double r_a, point b, double r_b, point c, double r_c) { // 
  if (r_a <= eps || r_b <= eps || r_c <= eps) return false; // 
  r_a = max(r_a, 0.0); r_b = max(r_b, 0.0); r_c = max(r_c, 0.0);
  if (inter(a, r_a, c, r_c, b, r_b)) return true;
  if (inter(b, r_b, a, r_a, c, r_c)) return true;
  if (inter(c, r_c, b, r_b, a, r_a)) return true;
  return false;
}

int main() {
  scanf("%lf %lf", &t1, &t2);
  readpoint(c); readpoint(h); readpoint(s);
  if (abs(s - c) + abs(h - s) <= abs(c - h) + t2) {
    printf("%lf\n", min(abs(c - h) + t2, abs(s - c) + abs(h - s) + t1));
  } else {
    double l, r, m;
    l = 0; r = min(abs(c - h) + t2, abs(s - c) + abs(h - s) + t1);
    while (r - l > eps) {
      //printf("%lf %lf\n", l, r);
      m = (r + l) / 2;
      if (check(c, m, s, abs(s - c) + t1 - m, h, abs(h - c) + t2 - m)) {
        l = m;
      } else {
        r = m;
      }
    }
    printf("%lf\n", l);
  }
  return 0;
}