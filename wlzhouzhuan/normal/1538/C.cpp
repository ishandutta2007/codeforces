// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx")
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

#define N 200005
int n, l, r, a[N];

void solve() {
  n = read(), l = read(), r = read();
  rep(i, 1, n) a[i] = read();
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int posL = lower_bound(a + 1, a + n + 1, l - a[i]) - a;
    posL = max(posL, i + 1);
    int posR = upper_bound(a + 1, a + n + 1, r - a[i]) - a - 1;
    posR = min(posR, n);
    ans += max(0, posR - posL + 1);
//    printf("i = %d, posL = %d, posR = %d\n", i, posL, posR);
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
}