#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, m, a[N], cnt[N], l[N], r[N], c[N], ans[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] <= n) ++cnt[a[i]];
  }
  for (int i = 1; i <= m; ++i) scanf("%d %d", &l[i], &r[i]);
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] >= i) {
      c[0] = 0;
      for (int j = 1; j <= n; ++j) c[j] = a[j] != i ? c[j - 1] : c[j - 1] + 1;
      for (int j = 1; j <= m; ++j) if (c[r[j]] - c[l[j] - 1] == i) ++ans[j];
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}