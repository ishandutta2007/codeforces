#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n % 2) res = res * x % mod;
    n /= 2;
    x = x * x % mod;
  }
  return res;
}

vl fac(4.1e6, 1);
vl invfac(fac.size(), 1);
vl inv(fac.size(), 1);

double calct0(int n, int m, int i) {
  double res = 0;
  int T = 1000;
  for (int t = 0; t < T; ++t) {
    int rem = i;
    for (int tt = 1; ; ++tt) {
      int x = rand() % (m + n - i + rem);
      if (x < rem) --rem;
      else if (x < rem + m) rem = i;
      else {
        res += tt - i + rem - 1;
        break;
      }
    }
  }
  return res / T;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, m;
  cin >> n >> m;
  for (int i = 2; i < (int)inv.size(); ++i) inv[i] = (mod - (mod / i) * (ll)inv[mod % i] % mod) % mod;
  for (int i = 2; i < (int)fac.size(); ++i) fac[i] = fac[i - 1] * i % mod;
  invfac.back() = mpow(fac.back(), mod - 2);
  for (int i = invfac.size() - 2; i > 0; --i) invfac[i] = invfac[i + 1] * (i + 1) % mod;
  for (int i = 1; i < 10000; ++i) {
    assert(fac[i] * invfac[i] % mod == 1);
    assert(i * inv[i] % mod == 1);
  }
  vl g(n + 1), invg(n + 1), p(n + 1), t0(n + 1);
  for (int i = 0; i < (int)g.size(); ++i) {
    invg[i] = fac[m + n - i - 1] * invfac[n - i] % mod;
    g[i] = invfac[m + n - i - 1] * fac[n - i] % mod;
    ll p0 = m * inv[m + n - i] % mod;
    ll q0 = (m + n - i) * inv[n - i] % mod;
    ll e0 = (m + n + 1) * inv[m + n - i + 1] % mod;
    t0[i] = e0 * p0 % mod * q0 % mod;
    if (i < min(10000LL, n)) {
      assert(g[i] * invg[i] % mod == 1);
      assert((mod + 1 - p0) * q0 % mod == 1);
    }
  }
  p[0] = 1;
  ll sump = 0;
  for (int i = 0; i <= n; ++i) {
    if (i > 0) {
      p[i] = sump * invg[i] % mod; 
    }
    ll mul = p[i] * g[i] % mod * m % mod * inv[n - i] % mod;
    sump = (sump + mul) % mod;
//    cerr << g[i] << ' ' << p[i] * 120 % mod << endl;
  }
  assert(p[n] == 1);
  vl f(n + 1);
  const int D = 48;
  if (1) {
    ll sumf = 0, addf = 0, sumdiv = 0;
    for (int i = 0; i <= n; ++i) {
      sumf = (sumf + addf) % mod;
      if (i > 0) {
        //f[i] = sumf * invg[i] % mod;
        f[i] = sumf * mpow(sumdiv, mod - 2) % mod;
      }
      ll dd = (m + n + 1) * inv[m + n - i + 1] % mod;
      ll mul = p[i] * g[i] % mod * m % mod * inv[n - i] % mod;
      sumdiv = (sumdiv + mul) % mod;
      sumf = (sumf + mul * (f[i] + t0[i] + dd)) % mod;
      addf = (addf + mul * dd) % mod;
//      cerr << (t0[i] * D % mod) / (double)D << ' ' << (f[i] * D % mod) / (double)D << endl;
//      if (i < n) cerr << calct0(n, m, i) << endl;
    }
  } else {
    for (int i = 0; i <= n; ++i) {
      if (i > 0) {
        f[i] = f[i] * invg[i] % mod;
      }
      for (int j = i + 1; j <= n; ++j) {
        ll d = j - i;
        ll dd = (m + n + 1) * inv[m + n - i + 1] % mod;
        ll mul = p[i] * g[i] % mod * m % mod * inv[n - i] % mod;
        f[j] = (f[j] + mul * (f[i] + t0[i] + (d + 1) * dd % mod)) % mod;
      }
      cerr << t0[i] * D % mod << ' ' << f[i] * D % mod << endl;
    }
  }
  cout << f[n] << endl;
  return 0;
}