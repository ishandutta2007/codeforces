#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 15;
const double eps = 1e-9;

int n, m[N], ord[N], mins;
double x[N], v[N], t, ct, tmp, mct;

bool cmp(int i, int j) {return x[i] < x[j];}

int main() {
  scanf("%d %lf", &n, &t);
  for (int i = 1; i <= n; ++i) scanf("%lf %lf %d", &x[i], &v[i], &m[i]);
  for (int i = 1; i <= n; ++i) ord[i] = i;
  sort(ord + 1, ord + 1 + n, cmp);
  ct = 0;
  while (ct < t) {
    mct = t - ct;
    mins = 0;
    for (int i = 1; i < n; ++i) {
      if (v[ord[i]] - v[ord[i + 1]] < eps) continue;
      tmp = (x[ord[i + 1]] - x[ord[i]]) / (v[ord[i]] - v[ord[i + 1]]);
      if (tmp < -eps) continue;
      if (tmp < mct) {
        mct = tmp;
        mins = i;
      }
    }
    for (int i = 1; i <= n; ++i) x[i] += v[i] * mct;
    ct += mct;
    if (mins != 0) {
      int i = mins;
      double v1 = v[ord[i]], v2 = v[ord[i + 1]];
      int m1 = m[ord[i]], m2 = m[ord[i + 1]];
      v[ord[i]] = ((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2);
      v[ord[i + 1]] = ((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%.12lf\n", x[i]);
  return 0;
}