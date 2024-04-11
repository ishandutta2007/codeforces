//CF 7C
#include<cstdio>

long long a, b, c, d, x, y;

long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long t1;
    t1 = gcd(b, a % b, y, x);
    y = y - a / b * x;
    return t1;
  }
}

int main() {
  scanf("%I64d %I64d %I64d", &a, &b, &c);
  d = gcd(a, b, x, y);
  if (c % d == 0) {
    printf("%I64d %I64d\n", -x * (c / d), -y * (c / d));
  } else {
    puts("-1");
  }
  return 0;
}