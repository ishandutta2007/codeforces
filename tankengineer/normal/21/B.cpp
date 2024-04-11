//21B
#include<cstdio>
int a, b, c, d, e, f;
int main() {
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  if (!a && !b && c) {
    puts("0");
    return 0;
  } 
  if (!d && !e && f) {
    puts("0");
    return 0;
  }
  if (a * e == b * d) {
    if (a * f == d * c) {
      puts("-1");
      return 0;
    }
    puts("0");
    return 0;
  }
  puts("1");
  return 0;
}