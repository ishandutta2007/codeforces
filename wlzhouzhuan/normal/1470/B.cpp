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

const int N = 1000005;
int a[N], p[N], d[N], n;
int pr[N], vis[N], len;
void sieve(int n) {
  vis[0] = vis[1] = 1, d[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i, d[i] = i;
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      d[pr[j] * i] = d[i] % pr[j] == 0 ? d[i] / pr[j] : d[i] * pr[j]; 
      if (i % pr[j] == 0) {
        break;
      }
    }
  }
}
signed main() {
  sieve(N - 5);
  int T = read();
  while (T--) {
    n = read();
    rep(i, 1, n) a[i] = read(), a[i] = d[a[i]];
    sort(a + 1, a + n + 1);
    int res0 = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j <= n && a[i] == a[j]) j++;
      res0 = max(res0, j - i);
      if ((j - i) % 2 == 0) {
        for (int k = i; k < j; k++) a[k] = 1;
      }
      i = j - 1;
    }
    sort(a + 1, a + n + 1);
    int res1 = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j <= n && a[i] == a[j]) j++;
      res1 = max(res1, j - i);
      i = j - 1;
    }
    int q = read();
    while (q--) {
      ll w = read();
      if (w == 0) printf("%lld\n", res0);
      else printf("%lld\n", res1);
    }
  }
  return 0;
}