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
const int N = 500005;
const int mod = 1e9 + 7;
ll a[N];
int cnt[60], n;
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      for (int j = 59; j >= 0; j--) {
        if (a[i] >> j & 1) {
          cnt[j]++;
        }
      }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ll x1 = 0, x2 = 0;
      for (int j = 59; j >= 0; j--) {
        if (a[i] >> j & 1) {
          x1 = (x1 + (1ll << j) % mod * cnt[j] % mod) % mod;
        }
      }
      for (int j = 59; j >= 0; j--) {
        if (a[i] >> j & 1) {
          x2 = (x2 + (1ll << j) % mod * n % mod) % mod;
        } else {
          x2 = (x2 + (1ll << j) % mod * cnt[j] % mod) % mod;
        }
      }
      ans = (ans + x1 % mod * x2 % mod) % mod;
    }
    printf("%lld\n", ans);
  }
}