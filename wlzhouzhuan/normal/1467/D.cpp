// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define poly vector<int>
#define SZ(a) int(a.size())
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
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

const int N = 5005;
const int mod = 1e9 + 7;
int dp[N][N], f[N], a[N], n, m, q;

void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int ans = 0;

int main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (i < n) add(dp[i + 1][j], dp[i][j - 1]);
      if (i > 1) add(dp[i - 1][j], dp[i][j - 1]);
    }
    //for (int i = 1; i <= n; i++) {
      //add(f[i], dp[i][j]);
      //f[i] = (1ll * f[i] * ((i > 1) + (i < n)) % mod + dp[i][j]) % mod;
      //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    //}
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i] = (f[i] + 1ll * dp[i][j] * dp[i][m - j] % mod) % mod;
    }
  }
  //for (int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
  for (int i = 1; i <= n; i++) ans = (ans + 1ll * f[i] * a[i]) % mod;
  while (q--) {
    int x = read(), y = read();
    ans = (ans - 1ll * f[x] * a[x] % mod + mod) % mod;
    a[x] = y;
    ans = (ans + 1ll * f[x] * a[x] % mod + mod) % mod;
    print(ans, '\n');
  }
}