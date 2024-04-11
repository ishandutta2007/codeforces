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
  ll r = 1;
  while (n) {
    if (n & 1) r = x * r % mod;
    x = x * x % mod;
    n /= 2;
  }
  return r;
}

vl fac(10000, 1);
vl invfac(fac.size(), 1);

ll bin(int k, int n) {
  return fac[n] * invfac[k] % mod * invfac[n-k] % mod;
}

ll f(int a, int b) {
  ll res = 0;
  for (int i = 0; i <= min(a, b); ++i) {
    res = (res + bin(i, a) * bin(i, b) % mod * fac[i]) % mod;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = fac[i-1] * i % mod;
    invfac[i] = mpow(fac[i], mod-2);
  }
  int a, b, c;
  cin >> a >> b >> c;
  cout << f(a, b) * f(b, c) % mod * f(a, c) % mod << endl;
  return 0;
}