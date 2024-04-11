//1182B
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps = 1e-10;

int n, t1, t2, k, u, v, srt[1005];
double ti[1005];

bool cmp(int i, int j) {return ti[i] > ti[j] || (fabs(ti[i] - ti[j]) < eps) && i < j;}

double cal(int v1, int v2) {
  double size = v1 * t1;
  size = size * (double)(100 - k) / 100;
  size = size + v2 * t2;
  return size;
}

int main() {
  scanf("%d %d %d %d", &n, &t1, &t2, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &u, &v);
    ti[i] = max(cal(u, v), cal(v, u));
    srt[i] = i;
  }
  sort(srt + 1, srt + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    printf("%d %.2lf\n", srt[i], ti[srt[i]]);
  }
  return 0;
}