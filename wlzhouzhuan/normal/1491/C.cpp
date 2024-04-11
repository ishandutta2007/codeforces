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
const int N = 123456;
ll a[N], d[N], n;
void work() {
  scanf("%lld", &n);
  for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]), d[i] = 0;
  d[n + 1] = 0;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    ll t = a[i];
    if (a[i] + d[i] >= 1) {
      a[i] += d[i];
      d[min(n + 1, i + a[i] + 1)]--, d[min(n + 1, i + t + 1)]++;
    } else {
      d[min(n + 1, i + 2)]--, d[min(n + 1, i + t + 1)]++;
      ll need = 1 - (a[i] + d[i]);
      a[i] = 1;
      d[i + 1] -= need, d[i + 2] += need;
    }
//    printf("When i = %lld, a = %lld\n", i, a[i]);
    if (a[i] > 1) {
      d[min(n + 1, i + 2)]--, d[min(n + 1, i + a[i] + 1)]++;
      ans += a[i] - 1; 
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}