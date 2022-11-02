//CF 1A
#include<stdio.h>

long long n, m, a;

int main() {
  scanf("%d %d %d", &n, &m, &a);
  printf("%I64d\n", (n / a + (n % a ? 1 : 0)) * (m / a + (m % a ? 1 : 0)));
  return 0;
}