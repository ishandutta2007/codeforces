// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 1005;
char a[N], b[N];
int k, n;

void solve() {
  scanf("%d%d", &n, &k);
  k = min(k, n);
  scanf("%s", a + 1);
  rep(i, 1, n) a[i] -= '0';
  a[n + 1] = 0;
  while (k--) {
    rep(i, 1, n) {
      if (a[i] == 0) {
        int t = (i > 1 && a[i - 1] == 1) + (i < n && a[i + 1] == 1);
        if (t == 1) b[i] = 1;
        else b[i] = 0;
      } else {
        b[i] = 1;
      }
    }
    rep(i, 1, n) a[i] = b[i];
  }
  rep(i, 1, n) printf("%d", a[i]);
  puts("");
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}