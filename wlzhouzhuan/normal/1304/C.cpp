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

const int N = 1000005;
int ini;
int t[N], n, m;
int T;

int main() {
  cin >> T; while (T--) {
    n = read(), ini = read();
    ll l = ini, r = ini; int ok = 0;
    for (rint i = 1; i <= n; i++) {
      t[i] = read();
      ll L = read(), R = read();
      if (ok) continue;
      l = l - (t[i] - t[i - 1]);
      r = r + (t[i] - t[i - 1]);
      l = max(l, L), r = min(r, R);
      //printf("l = %lld %lld\n", l, r);
      if (l > r) {
        ok = 1;
      }
    }
    if (ok) puts("NO"); else puts("YES");
  }
}