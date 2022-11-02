#include<cstdio>
#include<algorithm>
using namespace std;

int n, x, c[105], t1;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    c[i] *= (n - i + 1);
  }
  sort(c + 1, c + n + 1);
  t1 = 0;
  while (t1 < n && x - c[t1 + 1] >= 0) {
    ++t1;
    x -= c[t1];
  }
  printf("%d\n", t1);
  return 0;
}