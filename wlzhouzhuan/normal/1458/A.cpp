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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
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
ll a[N], b[N], n, m;
ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  scanf("%lld%lld", &n, &m);
  rep(i, 1, n) scanf("%lld", &a[i]);
  rep(i, 1, m) scanf("%lld", &b[i]);
  long long g = 0;
  rep(i, 2, n) if (g == 0) g = a[i] - a[1]; else g = gcd(g, a[i] - a[1]);
  rep(i, 1, m) {
    printf("%lld ", llabs(gcd(g, a[1] + b[i])));
  }
}