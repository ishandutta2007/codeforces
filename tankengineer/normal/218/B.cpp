#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 2005;

int n, m, a[N], b[N], c[N], t1, ans1, ans2;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) b[i] = c[i] = a[i];
  ans1 = 0; ans2 = 0;
  for (int i = 1; i <= n; ++i) {
    t1 = 1;
    while (b[t1] == 0) ++t1;
    for (int j = t1 + 1; j <= m; ++j) {
      if (b[j] != 0 && b[j] < b[t1]) t1 = j;
    }
    ans1 += b[t1]--;
    t1 = 1;
    while (c[t1] == 0) ++t1;
    for (int j = t1 + 1; j <= m; ++j) {
      if (c[j] != 0 && c[j] > c[t1]) t1 = j;
    }
    ans2 += c[t1]--;
  }
  printf("%d %d\n", ans2, ans1);
  return 0;
}