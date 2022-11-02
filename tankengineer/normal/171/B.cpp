//171B
#include<cstdio>

int n, ans, cnt;

int main() {
  scanf("%d", &n);
  ans = 1; cnt = 2;
  for (int i = 2; i <= n; i++) {
    ans = ans + cnt * 6;
    cnt += 2;
  }
  printf("%d\n", ans);
  return 0;
}