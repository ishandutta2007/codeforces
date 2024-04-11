//21C
#include<cstdio>

int n;
long long ans, cntl, sum[100005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  if (sum[n] % 3) {
    puts("0");
  } else {
    ans = 0; cntl = 0;
    for (int i = 1; i < n - 1; i++) {
      if (sum[i] == sum[n] / 3) cntl++;
    }
    for (int i = n; i > 2; i--) {
      if (sum[n] - sum[i - 1] == sum[n] / 3) ans += cntl;
      if (sum[i - 2] == sum[n] / 3) cntl--;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}