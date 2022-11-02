//171C
#include<cstdio>

int n, ans, t1;

int main() {
  scanf("%d", &n);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t1);
    ans += t1 * i;
  }
  printf("%d\n", ans);
  return 0;
}