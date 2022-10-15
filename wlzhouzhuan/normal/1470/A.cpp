// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 300005;

ll pref[N];
int a[N], b[N], c[N];
int n, m;

signed main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
      c[i] = read();
      pref[i] = pref[i - 1] + c[i];
    }
    long long ans = 1e18;
    b[n + 1] = 1e9;
    for (int i = n; i >= 1; i--) {
      b[i] = a[i] - i;
      b[i] = min(b[i + 1], b[i]);
    }
    ll pre = 0;
    for (int i = 0; i <= n; i++) {
      pre += c[a[i]];
      if (b[i + 1] + i >= 0) {
        ans = min(ans, pre + pref[n - i]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}