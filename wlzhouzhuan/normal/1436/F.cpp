// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define fir first
#define sec second
#define int long long

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 200005;
const int mod = 998244353;

vector<int> pr; 
int mu[N], vis[N];
void sieve(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.pb(i), mu[i] = -1;
    for (auto v: pr) {
      if (i * v > n) break;
      vis[i * v] = 1;
      if (i % v == 0) break;
      mu[i * v] = -mu[i];
    } 
  }
}

ll qpow(ll a, ll b = mod - 2) {
  a %= mod;
  if (b < 0) {
    return qpow(qpow(a), -b);
  }
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1; 
  }
  return res;
}
ll f[N];
int n, m;

signed main() {
  sieve(N - 1);
  n = N - 4, m = read();
  for (int i = 1; i <= m; i++) {
    int a = read(), x = read();
    f[a] += x;
  }
  ll ans = 0;
  for (int x = 1; x <= n; x++) if (mu[x]) {
    ll cnt = 0, sum = 0, sqr = 0;
    for (int y = x; y <= n; y += x) {
      cnt += f[y];
      sum = (sum + 1ll * y * f[y]) % mod;
      sqr = (sqr + 1ll * y * y % mod * f[y]) % mod;
    }
    ll delta = 0;
    if (cnt > 1) {
      ll c = cnt % mod * qpow(2, cnt - 3) % mod;
      ll d = (cnt - 1) % mod * qpow(2, cnt - 2) % mod;
      delta = (sum * sum % mod * c % mod + sqr * (d - c + mod) % mod) % mod;
      //printf("x = %d, delta = %lld\n", x, delta); 
      //printf("%lld %lld %lld %lld %lld\n", cnt, sum, sqr, c, d);
    }
    ans = (ans + 1ll * mu[x] * delta) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}