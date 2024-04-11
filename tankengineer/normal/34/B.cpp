#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, a[1005], ans;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i) {
    if (a[i] < 0) ans -= a[i];
  }
  printf("%d\n", ans);
  return 0;
}