//CF 10D
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k, t1, t2, a[505], b[505], f[505], fa[505], ans[505];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int j = 1; j <= m; j++) {
    scanf("%d", &b[j]);
  }
  
  for (int i = 1; i <= n; i++) {
    k = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j] && f[j] < f[k] + 1) {
        f[j] = f[k] + 1;
        fa[j] = k;
      } else if (a[i] > b[j] && f[j] > f[k]) {
        k = j;
      }
    }
  }
  k = max_element(f, f + m + 1) - f;
  t1 = k; t2 = 0;
  while (t1) {
    ans[++t2] = b[t1];
    t1 = fa[t1];
  }
  printf("%d\n", t2);
  for (int i = t2; i > 1; i--) {
    printf("%d ", ans[i]);
  }
  if (t2) printf("%d\n", ans[1]);
  return 0;
}