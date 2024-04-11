// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

char s[55][55];
int n, m;

bool get(int x, int y) {
  if (y == m) return 1;
  if (x == n) return 0;
  int t0 = 1e9, t1 = 1e9;
  for (int i = x; i <= n; i++) {
    for (int j = y; j <= m; j++) {
      if (s[i][j] == '*') {
        if (i > x) t0 = min(t0, i - x - 1 + j - y);
        if (j > y) t1 = min(t1, i - x + j - y - 1);
      }
    }
  }
  return t0 < t1;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int x = 1, y = 1;
  int ans = 0;
  while (1) {
    ans += s[x][y] == '*';
    if (x == n && y == m) break;
    get(x, y) ? ++x: ++y;
  }
  cout << ans;
}