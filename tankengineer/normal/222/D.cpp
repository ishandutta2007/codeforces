#include<cstdio>
#include<algorithm>
using namespace std;

int n, mini, a[200005], b[200005], ans;

int main() {
  scanf("%d %d", &n, &mini);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int j = 1; j <= n; ++j) scanf("%d", &b[j]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int t1 = 1;
  for (int i = n; i >= 1; --i) {
    while (t1 < n && a[i] + b[t1] < mini) ++t1;
    if (a[i] + b[t1] >= mini) {
      ++t1;
      ++ans;
    }
    if (t1 > n) break;
  }
  printf("1 %d\n", ans);
  return 0;
}