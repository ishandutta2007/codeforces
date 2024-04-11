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

const int N = 505;

ll a[N], ans;
int n;

void solve() {
  n = read();
  ans = 0;
  for (rint i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (n == 1) {
    printf("%lld\n", a[1]);
    return ;
  }
  if (n == 2) {
    printf("%lld\n", a[1] | a[2]);
    return ;
  } 
  for (rint i = 1; i <= n; i++) {
    for (rint j = i + 1; j <= n; j++) {
      for (rint k = j + 1; k <= n; k++) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
  solve();
  return 0;
}