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
#define SZ(x) (int(x.size()))
#define int long long
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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
int pos[N], a[N], b[N]; 
int n, m, k, d, n0, m0, Inv;
ll period;

int gcd(int n, int m) {
  return m ? gcd(m, n % m) : n;
}

vector<ll> skip;
//  x  x % x1 = n, x % x2 = m 
ll calc(int x1, int x2) {
  x2 -= x1;
  if (x2 % d) return -1;
  x2 /= d;
  ll t = 1ll * x2 * Inv % m0;
  if (t < 0) t += m0;
  return t * n + x1;
}

signed main() {
  n = read(), m = read(), k = read();
  d = gcd(n, m), n0 = n / d, m0 = m / d, period = 1ll * n / d * m;
  for (int i = 0; i < m0; i++) {
    if (1ll * i * n0 % m0 == 1) {
      Inv = i;
      break;
    }
  }
  memset(pos, -1, sizeof(pos));
  for (int i = 0; i < n; i++) {
    a[i] = read();
    pos[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    b[i] = read();
    if (pos[b[i]] != -1) {
      ll t = calc(pos[b[i]], i);
      if (t != -1) skip.pb(t);
    }
  }
  ll l = 0, r = 1ll << 60;
  while (l < r) {
    ll mid = l + r >> 1;
    ll rnk = mid;
    for (auto v: skip) rnk -= (mid - (v + 1) + period) / period;
    if (rnk >= k) r = mid;
    else l = mid + 1;
  }
  print(l, '\n');
}