//29B
#include<cstdio>
#include<cmath>

int l, d, v, g, r;
double t, t1;

int main() {
  scanf("%d %d %d %d %d", &l, &d, &v, &g, &r);
  t = d * 1.0 / v;
  t1 = fmod(t, (double)(g + r));
  if (t1 <= g - 1e-7) {
    t = l * 1.0 / v;
  } else {
    t += g + r - t1 + (l - d) * 1.0 / v;
  }
  printf("%.12lf\n", t);
  return 0;
}