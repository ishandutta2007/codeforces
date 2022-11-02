//16C
#include<cstdio>
#include<algorithm>

using namespace std;

int a, b, c, d, e, x, y;

int main() {
  scanf("%d %d %d %d", &x, &y, &a, &b);
  c = a; d = b; e = c % d;
  while (e) {
    c = d;
    d = e;
    e = c % d;
  }
  a /= d;
  b /= d;
  if (a > x || b > y) {
    puts("0 0");
    return 0;
  }
  c = min(x / a, y / b);
  a *= c; b *= c;
  printf("%d %d\n", a, b);
  return 0;
}