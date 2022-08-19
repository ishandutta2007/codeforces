#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

const int N = 1234567;

int x, y;
int z[N];

bool check(int pos, long long cx, long long cy, int last, int type) {
  if (pos == -1) {
    if (cx >= x && cy >= y) {
      return true;
    }
    return false;
  }
  if (z[pos] != last || type != 1) {
    if (check(pos - 1, min(cx * z[pos], x * 1LL), cy, z[pos], 0)) {
      return true;
    }
  }
  return check(pos - 1, cx, min(cy * z[pos], y * 1LL), z[pos], 1);
}

int main() {
  int a, b, h, w, n;
  scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", z + i);
  }
  sort(z, z + n);
  reverse(z, z + n);
  int ans = inf;
  for (int rot = 0; rot < 2; rot++) {
    x = (a + h - 1) / h;
    y = (b + w - 1) / w;
    if (x == 1 && y == 1) {
      ans = 0;
      break;
    }
    long long prod = 1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      prod *= z[i];
      if (prod >= x * y) {
        flag = true;
      }
      if (flag) {
        if (check(i, 1, 1, -1, -1)) {
          ans = min(ans, i + 1);
          break;
        }
      }
    }
    swap(h, w);
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}