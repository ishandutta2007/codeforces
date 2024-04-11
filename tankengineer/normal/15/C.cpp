//15C
#include<cstdio>

inline long long f(long long x) {
  return (((x + 1) & 1) * x) ^ (((x + 1) & 2) >> 1);
}

int n;
long long ans, x, y;

int main() {
  scanf("%d", &n);
  ans = 0;
  for (;n--;) {
    scanf("%I64d %I64d", &x, &y);
    ans ^= f(x - 1) ^ f(y + x - 1);
  }
  puts(ans ? "tolik" : "bolik");
  return 0;
}