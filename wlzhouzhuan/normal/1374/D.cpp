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

int n, k;
void solve() {
  n = read(), k = read();
  map <int, int> cnt;
  for (rint i = 1; i <= n; i++) {
    int x = read();
    if (x % k) cnt[k - x % k]++;
  }
  ll ans = 0;
  for (map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    ans = max(ans, 1ll + 1ll * it->first + 1ll * k * (it->second - 1));
  }
  printf("%lld\n", ans);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}