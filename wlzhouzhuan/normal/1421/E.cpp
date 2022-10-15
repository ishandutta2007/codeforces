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

const int N = 200005;
int n;
long long a[N], f[N][3][2];

void ckmax(ll &x, ll y) {
  if (x < y) x = y;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  if (n == 1) {
    printf("%lld\n", a[1]);
    return 0; 
  }
  memset(f, -0x3f, sizeof(f));
  f[0][0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      if (i & 1) { // choose +
        ckmax(f[i][(j + 1) % 3][1], f[i - 1][j][1] + a[i]);
        ckmax(f[i][(j + 1) % 3][0], f[i - 1][j][0] + a[i]);
      } else {
        ckmax(f[i][(j + 1) % 3][0], max(f[i - 1][j][0], f[i - 1][j][1]) + a[i]);
      }
      if (!(i & 1)) { // choose -
        ckmax(f[i][j][1], f[i - 1][j][1] - a[i]);
        ckmax(f[i][j][0], f[i - 1][j][0] - a[i]);
      } else {
        ckmax(f[i][j][0], max(f[i - 1][j][0], f[i - 1][j][1]) - a[i]) ;
      }
    }
  }
  printf("%lld\n", f[n][2 - n % 3][0]);
  return 0;
}