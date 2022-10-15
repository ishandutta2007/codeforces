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
#define int long long
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
const int N = 500005;
int a[N], ans[N], n;
int to[N], nxt[N], head[N], cnt;
void add(int u, int v) {
  to[++cnt] = v;
  nxt[cnt] = head[u];
  head[u] = cnt;
}
void solve() {
  n = read();
  rep(i, 1, n) a[i] = read(), head[i] = 0;
  cnt = 0;
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    add(u, v), add(v, u);
  }
  ans[0] = 0;
  rep(i, 1, n) ans[0] += a[i];
  vector<int> t;
  rep(i, 1, n) {
    for (int j = nxt[head[i]]; j; j = nxt[j]) {
      t.pb(a[i]);
    }
  } 
  sort(t.begin(), t.end(), greater<ll>());
  rep(i, 0, (int)t.size() - 1) {
    ans[i + 1] = ans[i] + t[i];
  }
  rep(i, 0, n - 2) {
    printf("%lld ", ans[i]);
  }
  puts("");
}
signed main() {
  int T;
  for (T = read(); T; T--) solve();
  return 0;
}