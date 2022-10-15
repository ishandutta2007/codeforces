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

int a, b;
pair <int, int> solve(int n, int m) {
  if (n == 0) {
    return make_pair(0, 0);
  }
  int len = 1 << (n - 1), mod = 1 << (2 * n - 2), kase;
  pair <int, int> tmp = solve(n - 1, m % mod);
  int x = tmp.first, y = tmp.second;
  kase = m / mod;
  switch (kase) {
    case 1: return make_pair(x, y + len); break;
    case 2: return make_pair(x + len, y + len); break;
    case 0: return make_pair(y, x); break;
    case 3: return make_pair(2 * len - y - 1, len - x - 1); break;
  }
}
int main() {
  scanf("%d%d", &a, &b);
  pair <int, int> ans = solve(a, b);
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}