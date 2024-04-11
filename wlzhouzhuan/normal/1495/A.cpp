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

#define N 500005
int x[N], y[N];
int n;

int main() {
  int t = read();
  while (t--) {
    n = read();
    int l1 = 0, l2 = 0;
    for (int i = 1; i <= 2 * n; i++) {
      int xX = read(), yY = read();
      if (xX == 0) x[++l1] = abs(yY);
      else y[++l2] = abs(xX);
    }
    sort(x + 1, x + l1 + 1);
    sort(y + 1, y + l2 + 1);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
    }
    printf("%.10lf\n", ans);
  }
}