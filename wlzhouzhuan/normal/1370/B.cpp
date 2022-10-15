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
    vector <int> odd, even;
    int n = read();
    for (rint i = 1; i <= 2 * n; i++) {
      int x = read();
      if (x & 1) odd.pb(i);
      else even.pb(i);
    }
    int len = even.size();
    if (len == 2 * n) {
      for (rint i = 0; i < len - 2; i += 2) {
        printf("%d %d\n", even[i], even[i + 1]);
      }
    } else {
      for (rint i = 0; i + 1 < len; i += 2) {
        printf("%d %d\n", even[i], even[i + 1]);
      }
      int lef = 2 * (n - 1) - (len / 2) * 2;
      for (rint i = 0; i < lef; i += 2) {
        printf("%d %d\n", odd[i], odd[i + 1]);
      }
    }
  }
  return 0;
}