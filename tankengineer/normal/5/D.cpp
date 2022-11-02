//CF 5D
#include<cstdio>
#include<cmath>

using namespace std;

inline double min(double a, double b) {return a < b ? a : b;}

double a, v, l, d, w, t;

int main() {
  scanf("%lf %lf %lf %lf %lf", &a, &v, &l, &d, &w);
  w = min(min(w, v), sqrt(2 * a * d));
  if (2 * a * d + w * w > 2 * v * v) {
    t = (d - v * v / a + w * w / a / 2) / v + (2 * v - w) / a;     
  } else {
    t = (2 * sqrt(a * d + w * w / 2) - w) / a;
  }
  l = l - d;
  if (v * v < l * a * 2 + w * w) {
    t += (l - v * v / a / 2 + w * w / a / 2) / v + (v - w) / a;
  } else {
    t += (-w + sqrt(w * w + 2 * a * l)) / a;
  }
  printf("%.12lf\n", t); 
}