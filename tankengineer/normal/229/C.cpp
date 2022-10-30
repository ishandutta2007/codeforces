#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, d[1000005], t1, t2;
long long ans;

int main() {
  scanf("%d %d", &n, &m);
  ans = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; ++i) d[i] = n - 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &t1, &t2);
    ans = ans - min(d[t1] - 1, d[t2] - 1) + min(n - 1 - d[t1], n - 1 - d[t2]);
    --d[t1];
    --d[t2];
  }
  printf("%I64d\n", ans);
  return 0;
}