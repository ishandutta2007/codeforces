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
#define int long long
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
int a[N], b[N], n;
int c[N], bit[31][2];
signed main() {
  n = read();
  ll sum = 0;
  for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  for (int i = 1; i <= n; i++) b[i] = read(), sum += b[i];
  if (sum % (2 * n)) return puts("-1") & 0;
  sum /= (2 * n);
//  fprintf(stderr, "sum = %lld\n", sum);
  for (int i = 1; i <= n; i++) {
    if ((a[i] + b[i] - sum) % n) return puts("-1") & 0;
    c[i] = (a[i] + b[i] - sum) / n;
    for (int j = 30; j >= 0; j--) {
      if (c[i] >> j & 1) bit[j][1]++;
      else bit[j][0]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    ll real_b = 0, real_c = 0;
    for (int j = 0; j <= 30; j++) {
      if (c[i] >> j & 1) {
        real_b += (1ll << j) * bit[j][1];
        real_c += (1ll << j) * n;
      } else {
        real_c += (1ll << j) * bit[j][1];
      }
    }
    if (real_b != a[i] || real_c != b[i]) return puts("-1") & 0;
  }
  for (int i = 1; i <= n; i++) print(c[i], " \n"[i == n]);
  return 0;
}