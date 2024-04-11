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

int bits[20], n;

int main() {
  n = read();
  for (rint i = 1; i <= n; i++) {
    int x = read();
    for (rint j = 0; j < 20; j++) {
      if (x >> j & 1) {
        bits[j]++;
      }
    }
  }  
  ll ans = 0;
  while (true) {
    ll x = 0;
    for (rint j = 19; j >= 0; j--) {
      if (bits[j]) {
        bits[j]--;
        x ^= 1 << j;
      }
    }
    if (!x) break;
    ans += x * x;
  }
  printf("%lld\n", ans);
  return 0;
}