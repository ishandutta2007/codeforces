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

const int N = 1000005;

char str[N];
int s[N];

void solve() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  for (rint i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (str[i] == '+' ? +1 : -1);
  }
  int cur = 0;
  ll ans = 0;
  for (rint i = 1; i <= n; i++) {
    while (i <= n && s[i] >= cur) i++;
    if (i > n) break;
    ans += 1ll * i * (cur - s[i]);
    cur = s[i];
  }
  printf("%lld\n", ans + n);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}