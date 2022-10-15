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

#define N 100005
int a[3][N], pre[3][N], suf[3][N];
int n;

void solve() {
  n = read();
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) a[i][j] = read();
    pre[i][0] = suf[i][n + 1] = 0;
    for (int j = 1; j <= n; j++) pre[i][j] = pre[i][j - 1] + a[i][j];
    for (int j = n; j >= 1; j--) suf[i][j] = suf[i][j + 1] + a[i][j]; 
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    ckmin(ans, max(suf[1][i + 1], pre[2][i - 1]));
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}