#include<cstdio>

long long c[9], a, n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    c[i % 9]++;
    a -= n / i;
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      a += c[i] * c[j] * c[i * j % 9];
    }
  }
  printf("%I64d\n", a);
  return 0;
}