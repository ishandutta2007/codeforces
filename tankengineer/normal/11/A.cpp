//CF 11A
#include<cstdio>

int n;
long long d, b[1000005], ans, t1;

int main() {
  scanf("%d %I64d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &b[i]);
    if (b[i] <= b[i - 1]) {
      t1 = (b[i - 1] - b[i]) / d + 1;
      ans += t1;
      b[i] = b[i] + t1 * d;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}