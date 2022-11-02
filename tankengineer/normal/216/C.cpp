//c
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 10005;

int n, m, k, sum[N], p[N];
bool flag;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  sum[1] = k;
  for (int i = 2; i <= n + m; ++i) {
    sum[i] = sum[i - 1];
    if (i > n - 1) sum[i] = max(sum[i], sum[i - n + 1] + 1);
    if (i > n) sum[i] = max(sum[i], sum[i - n] + k);
  }
  p[1] = k;
  for (int i = 2; i <= n + m; ++i) {
    p[i] = sum[i] - sum[i - 1];
  }
  printf("%d\n", sum[n + m]);
  flag = false;
  for (int i = 1; i <= n + m; ++i) {
    for (int j = 1; j <= p[i]; ++j) {
      if (flag) printf(" "); else flag = true;
      printf("%d", i);
    }
  }
  return 0;
}