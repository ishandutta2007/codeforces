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

const int N = 2000005;
const ll mod = 1e9 + 7;

ll dp[N];

int main() {
  dp[1] = dp[2] = 0;
  for (rint i = 3; i <= 2e6; i++) {
    dp[i] = (dp[i - 1] + 2ll * dp[i - 2]) % mod;
    if (i % 3 == 0) dp[i] = (dp[i] + 4) % mod;
  }
  int T = read();
  while (T--) {
    int x = read();
    printf("%lld\n", dp[x]);
  }
  return 0;
}