//CF 1C
#include<stdio.h>
#include<math.h>
using namespace std;
const double pi = 3.1415926536;
double x[5], y[5], a[5], b[5], c[5], cx, cy, dgr, r;
double fgcd(double a, double b) {return b < 1e-4 ? a : fgcd(b, fmod(a, b));}
int main() {
  for (int i = 1; i <= 3; i++) scanf("%lf %lf", &x[i], &y[i]);
  for (int i = 1; i <= 2; i++) {
    a[i] = x[i] - x[i + 1];
    b[i] = y[i] - y[i + 1];
    c[i] = -(x[i] * x[i] + y[i] * y[i] - x[i + 1] * x[i + 1] - y[i + 1] * y[i + 1]) / 2;
  }
  cx = (c[1] * b[2] - b[1] * c[2]) / (a[2] * b[1] - a[1] * b[2]);
  cy = (c[2] * a[1] - c[1] * a[2]) / (a[2] * b[1] - a[1] * b[2]);
  r = sqrt((x[1] - cx) * (x[1] - cx) + (y[1] - cy) * (y[1] - cy));
  dgr = fgcd(pi * 2, fgcd(fabs(atan2(x[2] - cx, y[2] - cy) - atan2(x[1] - cx, y[1] - cy)), 
                          fabs(atan2(x[3] - cx, y[3] - cy) - atan2(x[1] - cx, y[1] - cy))));
  printf("%lf\n", r * r * sin(dgr) * pi / dgr);
  return 0;
}