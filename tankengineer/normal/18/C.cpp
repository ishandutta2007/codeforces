//18C
#include<cstdio>

int n, sum[100005], ans;

int main() {
  scanf("%d", &n);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  for (int i = 1; i < n; i++) {
    if (sum[n] - sum[i] == sum[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}