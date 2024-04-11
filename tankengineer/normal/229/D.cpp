#include<cstdio>
#include<algorithm>
using namespace std;

int sum[5005], f[5005], g[5005], q[5005], a[5005], t1, n, qhead, qtail;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[n - i + 1]);
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i];
  }
  qhead = qtail = 1; q[1] = n + 1;
  for (int i = n; i >= 1; --i) {
    while (qtail > qhead && sum[q[qhead + 1] - 1] - sum[i - 1] >= f[q[qhead + 1]]) ++qhead;
    f[i] = sum[q[qhead] - 1] - sum[i - 1];
    g[i] = g[q[qhead]] + 1;
    while (qtail > qhead && f[i] - sum[i - 1] < f[q[qtail]] - sum[q[qtail] - 1]) --qtail;
    q[++qtail] = i;
  }
  //for (int i = 1; i <= n; ++i) printf("%d\n", g[i]);
  printf("%d\n", n - g[1]);
  return 0;
}