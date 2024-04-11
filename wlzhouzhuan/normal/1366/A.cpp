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

long long a, b;
bool check(long long x) {
  if (a - x < 0 || b - x < 0 || a - x + b - x < x) return 0;
  else return 1;
}

int main() {
  int T;
  scanf("%d", &T); 
  while (T--) {
    scanf("%lld%lld", &a, &b);
    long long l = 1, r = 1e9, ans = 0;
    while (l < r) {
      long long mid = l + r >> 1;
      if (check(mid)) l = mid + 1, ans = mid;
      else r = mid;
    }
    printf("%lld\n", ans);
  }
  return 0;
}