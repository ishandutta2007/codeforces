//18B
#include<cstdio>

int n, d, m, l;
long long right, left;

int main() {
  scanf("%d %d %d %d", &n, &d, &m, &l);
  right = 0; left = l;
  for (int i = 0; i < n; i++) {
    right = right + m;
    if ((left / d + 1) * d < right) break;
    if (i < n - 1) left =
     left + m;
  }
  left = (left / d + 1) * d;
  printf("%I64d\n", left);
  return 0;
}