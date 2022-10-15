// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

void ckmax(int &a, int b) {
  if (a < b) a = b;
}
void ckmin(int &a, int b) {
  if (a > b) a = b;
}

const int N = 3502;
int a[N], n, m, t;

int main() {
  int T = read();
  while (T--) {
    n = read(), m = read(), t = read();
    for (rint i = 1; i <= n; i++) {
      a[i] = read();
    } 
    if (t >= m - 1) {
      int ans = 0;
      for (rint i = 1; i <= m; i++) ckmax(ans, a[i]);
      for (rint i = n; i >= n - m + 1; i--) ckmax(ans, a[i]);
      printf("%d\n", ans);
    } else {
      int ans = 0, dlt = m - t - 1;
      for (rint left = 0; left <= t; left++) {
        rint right = t - left;
        int l = left + 1, r = n - right;
        rint res = 1e9;
        for (rint i = 0; i <= dlt; i++) {
          rint j = dlt - i;
          ckmin(res, max(a[l + i], a[r - j]));
        }
        ckmax(ans, res);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}