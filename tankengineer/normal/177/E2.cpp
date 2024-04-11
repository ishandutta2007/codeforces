//177E
#include<cstdio>
#include<algorithm>
using namespace std;

long long p, n, c, a[10005], b[10005], sum, l, r, m, ansr, ansl;

long long check(const long long x) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    if (ret + x / b[i] > c && a[i] != 0) return c + 1;
    ret += x / b[i] * a[i] + (x % b[i]) * a[i] / b[i];
    if (ret > c) return c + 1;
  }
  return ret;
}

int main() {
  p = 1000000000; p *= p * 4;
  scanf("%I64d %I64d", &n, &c);
  c -= n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i], &b[i]);
    sum += a[i];
  }
  if (sum == 0 && c == 0) {
    printf("-1\n");
    return 0;
  }
  if (sum == 0 && c != 0 || c < 0) {
    printf("0\n");
    return 0;
  }

  l = 0; r = p + 5;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m) < c) l = m; else r = m;
  }
  ansl = l;
  while (check(ansl + 1) < c) ansl++;

  l = 0; r = p + 5;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m) <= c) l = m; else r = m;
  }
  ansr = r;
  while (check(ansr - 1) > c) ansr--;

  printf("%I64d\n", max(0ll, ansr - ansl - 1));
  return 0;
}