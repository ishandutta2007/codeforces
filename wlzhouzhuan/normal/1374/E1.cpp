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

const int N = 200005;
const int inf = 2147483647;

vector <int> a11, a01, a10;
int n, k;

int main() {
  n = read(), k = read();
  for (rint i = 1; i <= n; i++) {
    int t = read(), p1 = read(), p2 = read();
    if (p1 && p2) a11.pb(t);
    else if (p1) a10.pb(t);
    else if (p2) a01.pb(t);
  }
  sort(a11.begin(), a11.end());
  sort(a10.begin(), a10.end());
  sort(a01.begin(), a01.end());
  int L11 = a11.size(), L10 = a10.size(), L01 = a01.size();
  for (rint i = 1; i < L11; i++) a11[i] += a11[i - 1];
  for (rint i = 1; i < L10; i++) a10[i] += a10[i - 1];
  for (rint i = 1; i < L01; i++) a01[i] += a01[i - 1];
  int ans = inf;
  for (rint i = 0; i <= L11; i++) {
    if (k - i <= L10 && k - i <= L01) {
      int t = i > 0 ? a11[i - 1] : 0;
      t += k - i > 0 ? a10[k - i - 1] + a01[k - i - 1] : 0;
      ans = min(ans, t);
    }
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}