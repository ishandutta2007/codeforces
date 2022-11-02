//177E
#include<cstdio>
#include<algorithm>
using namespace std;

long long p, n, c, a[10005], b[10005], sum, l, r, m, ansr, ansl;

long long check(const int x) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += a[i] * x / b[i];
  }
  return ret;
}

int main() {
  p = 1000000000; p *= p;
  scanf("%I64d %I64d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i], &b[i]);
    sum += a[i];
    if (a[i] != 0) p = min(p, b[i] * c / a[i] + 1);
  }
  if (sum == 0) {
    printf("-1\n");
    return 0;
  }
  c -= n;
  l = 0; r = p;
  if (check(0) > c || check(r) < c) {
    printf("0\n");
    return 0;
  }
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m) < c) l = m; else r = m;
  }
  ansl = l;
  if (check(ansl + 1) != c) ansl++;
  l = 0; r = p;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m) <= c) l = m; else r = m;
  }
  ansr = r;
  if (check(ansr - 1) != c) ansr--;
  printf("%I64d\n", max(0ll, ansr - ansl - 1));
  return 0;
}