//CF 6A
#include<stdio.h>

int a, b, c, d;

bool tri(int a, int b, int c) {return a + b > c && a + c > b && b + c > a;}
bool seg(int a, int b, int c) {return a + b == c || a + c == b || b + c == a;}

int main() {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (tri(a, b, c) || tri(b, c, d) || tri(a, b, d) || tri(a, c, d)) puts("TRIANGLE");
  else if (seg(a, b, c) || seg(a, c, d) || seg(a, b, d) || seg(b, c, d)) puts("SEGMENT");
  else puts("IMPOSSIBLE");
  return 0;
}