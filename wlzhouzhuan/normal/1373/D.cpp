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

/*
dp[i][0] 
dp[i][1] 
dp[i][2]  
*/
ll dp[N][3], a[N];
int n;

void solve() {
  n = read();
  for (rint i = 1; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
  for (rint i = 1; i <= n; i++) a[i] = read();
  for (rint i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + (i & 1 ? a[i] : 0);
    if (i >= 2) dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + (i & 1 ? a[i - 1] : a[i]);
    dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + (i & 1 ? a[i] : 0);
    //printf("dp[%d] [0] = %lld, [1] = %lld, [2] = %lld\n", i, dp[i][0], dp[i][1], dp[i][2]);
  }
  printf("%lld\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}