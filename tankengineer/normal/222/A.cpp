#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, l, ans, a[100005];

int gcd(const int x, const int y) {
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
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  l = gcd(n, k - 1);
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    int j = (i + k - 1) > n ? i + k - 1 - n : i + k - 1;
    if (a[i] != a[j]) ans = i;
    a[i] = a[j];
  }
  for (int i = 2; i <= n; ++i) {
    if (a[i] != a[i - 1]) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}