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
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define sec second

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

bool cross(int l1, int r1, int l2, int r2) {
  return max(l1, l2) <= min(r1, r2);
}
int n, x, m;

void solve() {
  scanf("%d%d%d", &n, &x, &m);
  int l = x, r = x;
  for (rint i = 1; i <= m; i++) {
    int L = read(), R = read();
    if (cross(l, r, L, R)) {
      l = min(l, L);
      r = max(r, R);
    }
  }  
  printf("%d\n", r - l + 1);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}