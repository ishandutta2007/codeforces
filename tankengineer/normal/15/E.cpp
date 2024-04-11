//15E
#include<cstdio>

int n;
long long a, b, c, p;

//b: 3 2 c: a: 

int main() {
  p = 1000000009;
  scanf("%d", &n);
  a = 1; b = 2; c = 4;
  for (int i = 1; i < n / 2; i++) {
    c = (c * a) % p;
    b = (b + c) % p;
    a = (a * 2 + 3) % p;
  }
  printf("%I64d\n", (b * b + 1) * 2 % p);
  return 0;
}