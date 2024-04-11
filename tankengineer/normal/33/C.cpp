#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, sum[N], sum2[N], a[N], best[N], best2[N], ans, sums;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] - a[i] * 2;
  sum2[n + 1] = 0;
  for (int i = n; i >= 1; --i) sum2[i] = sum2[i + 1] - a[i] * 2;
  best[0] = 0;
  for (int i = 1; i <= n; ++i) best[i] = max(best[i - 1], sum[i]);
  best2[n + 1] = 0;
  for (int i = n; i >= 1; --i) best2[i] = max(best2[i + 1], sum2[i]);
  for (int i = 1; i <= n; ++i) sums += a[i];
  ans = sums;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, max(sums + best[i] + best2[i + 1], sums + best[i - 1] + best2[i]));
    //printf("%d %d %d\n", sums, best[i], best2[i]);
  }
  printf("%d\n", ans);
  return 0;
}