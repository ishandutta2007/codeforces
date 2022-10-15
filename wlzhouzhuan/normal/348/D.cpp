// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 3005;
const int mod = 1e9 + 7;
 
char a[N][N];
int dp[N][N];
int n, m;

int solve(int x1, int y1, int x2, int y2) {
  if (a[x1][y1] == '#' || a[x2][y2] == '#') return 0;
  memset(dp, 0, sizeof(dp));
  dp[x1][y1] = 1;
  for (int i = x1; i <= n; i++) {
    for (int j = y1; j <= m; j++) {
      if (i == x1 && j == y1) continue;
      if (a[i][j] == '#') continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }
  return dp[x2][y2];
}

int main() {
  n = read(), m = read();
  rep(i, 1, n) scanf("%s", a[i] + 1);
  printf("%d\n", (1ll * solve(1, 2, n - 1, m) * solve(2, 1, n, m - 1) % mod - 1ll * solve(1, 2, n, m - 1) * solve(2, 1, n - 1, m) % mod + mod) % mod);
  return 0;
}