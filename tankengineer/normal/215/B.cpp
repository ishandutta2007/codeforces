#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 5005;

int n, m, x[N], a[N], b[N], a1, b1;
long double ans, tmp, A, B, R12, P1, P2;

int main() {
  scanf("%d", &n);
  x[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
    x[0] = max(x[0], x[i]);
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);  
  ans = 0;
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
  scanf("%d %d", &a1, &b1);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      A = a1 * 1.0; B = b1 * 1.0; R12 = x[0] * x[0] * 1.0; P1 = a[j] * 1.0; P2 = b[i] * 1.0;
      tmp = sqrt((B * P1 * R12) / (A * P2 + B * P1));
      //printf("%.12lf\n", (double)tmp);
      ans = max(tmp, ans);
    }
  }
  printf("%.12lf\n", (double)ans);
  //scanf("%d", &n);
  return 0;
}