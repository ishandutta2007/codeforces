// Author: wlzhouzhuan
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

int dp[505];
void init() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= 500; i++) {
    if (i >= 6) ckmin(dp[i], dp[i - 6] + 15);
    if (i >= 8) ckmin(dp[i], dp[i - 8] + 20);
    if (i >= 10) ckmin(dp[i], dp[i - 10] + 25);
  }
  for (int i = 499; i >= 0; i--) ckmin(dp[i], dp[i + 1]);
}

void solve() {
  ll n; scanf("%lld", &n);
  if (n <= 120) print(dp[n], '\n');
  else {
    ll qwq = (n - 450) / 6;
    print(qwq * 15 + dp[n - qwq * 6], '\n');
  }
}

int main() {
  init();
  int T = read();
  while (T--) solve();
  return 0;
}