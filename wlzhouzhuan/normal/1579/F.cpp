// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

void solve() {
  int n, m;
  n = read(), m = read();
  vector<int> a(n), vis(n);
  rep(i, 0, n - 1) a[i] = read(), vis[i] = 0;
  int ans = 0;
  rep(i, 0, n - 1) if (!vis[i]) {
    int j = i;
    vector<int> cyc;
    while (!vis[j]) {
      vis[j] = 1, cyc.pb(a[j]);
      j = (j + m) % n;
    }
    /*
    printf("find a cycle!\n");
    for (auto v: cyc) printf("%d ", v);
    puts("");
    */
    bool all0 = 1, all1 = 1;
    for (auto it: cyc) all0 &= !it, all1 &= it;
    if (all1) {
      puts("-1");
      return ;
    }
    if (all0) continue;
    int bg = 0, ed = SZ(cyc) - 1;
    while (cyc[bg]) bg++;
    while (cyc[ed]) ed--;
    ckmax(ans, bg + SZ(cyc) - 1 - ed);
    rep(j, bg, ed) {
      if (!cyc[j]) continue;
      int k = j, len = 0;
      while (cyc[k]) len++, k++;
      j = k;
      ckmax(ans, len);
    }
  }
  D("ans = ");
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}