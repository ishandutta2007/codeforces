//CF 11B
#include<cstdio>

int x, k, s;

int main() {
  scanf("%d", &x);
  x = x < 0 ? -x : x;
  k = 0;
  while (s < x || (x ^ s) % 2) {
    s += ++k;
  }
  printf("%d\n", k);
  return 0;
}