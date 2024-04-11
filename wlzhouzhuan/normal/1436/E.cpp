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
#define fir first
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

const int N = 110005;

int ok[N];
int pre[N], lst[N];
int a[N], n;

struct Bit {
  int c[N];
  void init() {
    memset(c, 0x3f, sizeof(c));
    c[0] = 0;
  }
  void add(int x, int v) {
    while (x < N) {
      c[x] = min(c[x], v);
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 1e9;
    while (x > 0) {
      ret = min(ret, c[x]);
      x ^= x & -x;
    }
    return ret;
  }
} bit;

int main() {
  n = read();
  bool same = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read(), same &= a[i] == 1;
    pre[i] = lst[a[i]], lst[a[i]] = i;
  }
  if (same) {
    puts("1"); return 0;
  }
  bit.init();
  for (int i = 1; i <= n + 1; i++) bit.add(i, lst[i]);
  for (int i = 1; i <= n + 1; i++) {
    if (bit.qry(i - 1) > lst[i]) ok[i] = 1;
  }
  for (int i = n; i >= 1; i--) {
    bit.add(a[i], pre[i]);
    if (bit.qry(a[i] - 1) > pre[i]) ok[a[i]] = 1;
  }
  int cur = 1;
  while (ok[cur]) cur++;
  printf("%d\n", cur);
  return 0;
}