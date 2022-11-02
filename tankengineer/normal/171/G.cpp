//171G
#include<cstdio>

int t1, t2, t3, n;

int main() {
  scanf("%d %d %d", &t1, &t2, &n);
  for (int i = 2; i <= n; i++) {
    t3 = t1 + t2;
    t1 = t2; t2 = t3;
  }
  printf("%d\n", t2);
  return 0;
}