//CF 6C
#include<cstdio>

int n, t[100005], ans, sum[100005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    sum[i] = sum[i - 1] + t[i];
  }
  
  if (n == 1) {
    printf("1 0\n");
    return 0;
  }
  
  ans = 1;
  while (sum[ans] <= sum[n] - sum[ans + 1]) ans++;
  
  printf("%d %d\n", ans, n - ans);
  
  return 0;
}