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

ll pw[20];
int n, k;

void solve() {
  scanf("%d%d", &n, &k);
  ll ans = 5e18;
  for (rint lst = 0; lst <= 9; lst++) {
    for (rint len = n / 9; len >= 0; len--) {
      int tot = 0;
      for (rint i = 0; i <= k; i++) {
        if (lst + i < 10) tot += len * 9 + lst + i;
        else tot += (lst + i - 10) + 1;
      }
      if (tot > n || (n - tot) % (k + 1) != 0) continue;
      int need = (n - tot) / (k + 1);
      ll cur = lst, t = len + 1;
      for (rint i = 1; i <= len; i++) cur += pw[i] * 9;
      if (need >= 8) {
        need -= 8;
        cur += pw[t++] * 8;
      }
      while (need >= 9) {
        need -= 9;
        cur += pw[t++] * 9; 
      }
      cur += pw[t++] * need;
      ans = min(ans, cur); 
    }
  }
  printf("%lld\n", ans == 5e18 ? -1 : ans);
}

int main() {
  pw[0] = 1;
  for (rint i = 1; i < 20; i++) pw[i] = pw[i - 1] * 10;
  int T = read();
  while (T--) solve();
  return 0;
}