//171A
#include<cstdio>

int t1, t2, rev;

int main() {
  scanf("%d %d", &t1, &t2);
  while (t2) {
    rev = rev * 10 + t2 % 10;
    t2 = t2 / 10;
  }
  printf("%d\n", t1 + rev);
  return 0;
}