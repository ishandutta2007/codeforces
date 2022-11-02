//CF 9C
#include<stdio.h>

int n, ans, t1, rck[10];
bool flag = false;

int main() {
  scanf("%d", &n);
  t1 = 0;
  while (n) {
    rck[++t1] = n % 10;
    n /= 10;
  }
  for (int i = t1; i >= 1; i--) {
    if (rck[i] > 1) flag = true;
    if (flag || rck[i]) n = n * 10 + 1; else n = n * 10;
  }
  t1 = 0;
  while (n > 0) {
    ans = ans + (n % 10 ? (1 << t1) : 0);
    t1++;
    n /= 10;
  }
  printf("%d\n", ans);
  return 0;
}