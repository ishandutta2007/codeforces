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

const int N = 200005;
int a[N];
int n, m, A, B;

void solve() {
  n = read(), m = read(), A = read(), B = read();
  rep(i, 1, m) a[i] = read(); sort(a + 1, a + m + 1);
  int lim1 = abs(A - B) - 1, lim2 = (A < B ? B - 2 : n - B - 1), ans = 0;
  per(i, m, 1) {
    if (lim1 <= 0) break;
    if (lim2 && a[i] <= lim2) {
      lim2--, lim1--, ans++;
    }
  }
  printf("%d\n", ans);
  return ;
}

int main() {
  for (int T = read(); T; T--) {
    solve();
  }
  return 0;
}