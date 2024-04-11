#include <bits/stdc++.h>
using namespace std;

struct Vec {
  double x, y;
  friend Vec operator + (Vec a, Vec b) {
    return (Vec){a.x + b.x, a.y + b.y};
  }

  friend Vec operator - (Vec a, Vec b) {
    return (Vec){a.x - b.x, a.y - b.y};
  }

  void input(void) {
    cin >> x >> y;
  }

  friend Vec operator * (Vec a, double b) {
    return (Vec){a.x * b, a.y * b};
  }

  friend Vec operator / (Vec a, double b) {
    return (Vec){a.x / b, a.y / b};
  }

  friend double operator * (Vec a, Vec b) {
    return a.x * b.x + a.y * b.y;
  }

  double Len(void) {
    return sqrt(x * x + y * y);
  }
  void out() {
    cout << x <<' ' << y << endl;
  }
}v, w, s, t, V;

double vm, T;

int main() {
  s.input(); t.input();
  V = t - s;
  double All = V.Len();
  cin >> vm >> T;
  v.input(); w.input();
  double l = 0, r = T * 2;
  for(int i = 0; i < 1000; ++ i)  {
    double mid = (l + r) * 0.5;
    Vec ns = s + v * mid;
    if((t - ns).Len() <= (mid) * vm) {
	r = mid;
    }
    else l = mid;
  }
  if(l <= T) {
    printf("%.15lf\n", l);
    return 0;
  }
  else {
    double ans = T;
    s = s + (v * T);
    double l = 0, r = 1e12;
    for(int i = 0; i < 1000; ++ i)  {
      double mid = (l + r) * 0.5;
      Vec ns = s + w * mid;
      if((t - ns).Len() <= (T + mid) * vm) {
	r = mid;
      }
      else l = mid;
    }
    printf("%.15lf\n", l + ans);
  }
}