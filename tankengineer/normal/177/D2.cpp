//177D
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, c, a[100005], b[100005], sum[100005];

int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int j = 1; j <= m; j++) {
    scanf("%d", &b[j]);
    sum[j] = sum[j - 1] + b[j];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i] + sum[min(i, m)] - sum[max(0, i - n + m - 1)]) % c;
  }
  for (int i = 1; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n]);
  return 0;
}