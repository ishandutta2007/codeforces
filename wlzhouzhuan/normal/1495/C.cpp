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

const int N = 555;
char a[N][N];
int n, m;

void solve() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'X') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }
  int n2 = n / 3 * 3;
  for (int i = 1; i <= n2; i += 3) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = 1;
    }
    bool flag = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i + 1][j] || a[i + 2][j]) {
        a[i + 1][j] = a[i + 2][j] = 1, flag = 1;
        break;
      }
    }
    if (!flag) {
      a[i + 1][1] = a[i + 2][1] = 1;
    }
  }
  if (n == n2) {
    for (int j = 1; j <= m; j++) {
      if (a[n][j]) {
        a[n - 1][j] = 1;
      }
    }
  }
  else if (n == n2 + 1) {
    for (int j = 1; j <= m; j++) {
      a[n][j] = 1;
    }
  }
  else {
    for (int j = 1; j <= m; j++) {
      a[n - 1][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) putchar('X');
      else putchar('.');
    }
    puts("");
  }
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}