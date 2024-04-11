//CF 4B
#include<stdio.h>
int n, sum, mint[32], maxt[32], t[32];
int main() {
  scanf("%d %d", &n, &sum);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &mint[i], &maxt[i]);
    t[i] = mint[i];
    sum -= mint[i];
  }
  if (sum < 0) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    while (sum && t[i] < maxt[i]) {
      sum--;
      t[i]++;
    }
  }
  
  if (sum > 0) {
    puts("NO");
    return 0;
  }
  
  puts("YES");
  for (int i = 1; i < n; i++) {
    printf("%d ", t[i]);
  }
  printf("%d\n", t[n]);
  
  return 0;
}