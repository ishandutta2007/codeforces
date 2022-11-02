#include<cstdio>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

long long n, m, cntx[2], cnty[2], x, y, x1, y1, x2, y2, ans, cnt;

inline long long gcd(const int x, const int y) {
  if (x == 0 || y == 0) return x + y;
  int a = x, b = y, c = x % y;
  while (c) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int main() {
  scanf("%d %d", &n, &m);
  ans = 0;
  cntx[0] = (n / 2 + 1);
  cntx[1] = (n + 1) / 2;
  cnty[0] = (m / 2 + 1);
  cnty[1] = (m + 1) / 2;
  for (int i = 0; i < 64; ++i) {
    x = (i & 1) == 1; y = (i & 2) == 2;
    x1 = (i & 4) == 4; y1 = (i & 8) == 8;
    x2 = (i & 16) == 16; y2 = (i & 32) == 32;
    if (((x2 - x1) * y + (y1 - y2) * x + x1 * y2 - x2 * y1) % 2 == 0) {
      ans += cntx[x] * cntx[x1] * cntx[x2] * cnty[y] % MOD * cnty[y1] * cnty[y2] % MOD;
      ans %= MOD;
    }
  }
  ans -= (n + 1) * (m + 1);
  ans %= MOD;
  if (ans < 0) ans += MOD;
  for (int dx = 0; dx <= n; ++dx) {
    for (int dy = 0; dy <= m; ++dy) {
      if (dx == 0 && dy == 0) continue;
      cnt = (1 + (dx != 0)) * (1 + (dy != 0));
      ans -= (n - dx + 1) * (m - dy + 1) * 3 * gcd(dx, dy) * cnt;
      ans %= MOD;
      if (ans < 0) ans += MOD;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}