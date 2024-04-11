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

int main() {
  int T = read();
  while (T--) {
    int x = read();
    if (x == 1) { puts("FastestFinger"); continue; }
    if (x == 2) { puts("Ashishgup"); continue; }
    if (x & 1) puts("Ashishgup");
    else {
      vector <int> yz;
      int maxf = 0;
      for (rint i = 2; i * i <= x; i++) {
        if (x % i == 0) {
          if (i & 1) {
            yz.pb(i);
            maxf = max(maxf, i);
          }
          if (x / i != i && ((x / i) & 1)) {
            yz.pb(x / i);
            maxf = max(maxf, x / i);
          }
        }
      }
      if (!yz.size()) puts("FastestFinger");
      else if (x / maxf > 2) puts("Ashishgup");
      else if (yz.size() > 1) puts("Ashishgup");
      else puts("FastestFinger");
    }
  }
  return 0;
}