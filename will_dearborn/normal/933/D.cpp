#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll s2(ll n) {
  n %= mod;
  return n * (n - 1) % mod;
}

ll s3(ll n) {
  n %= mod;
  return n * (n-1) % mod * (n-2) % mod;
}

ll eval(vl p, ll t) {
  ll res = 0;
  for (int i = p.size() - 1; i >= 0; --i) {
    res = (res * t + p[i]) % mod;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n;
  cin >> n;
  vl p(4);
  ll inv2 = mpow(2, mod-2);
  ll inv3 = mpow(3, mod-2);
  p[3] = (inv3) % mod;
  p[2] = (-(n + 2) % mod * inv2) % mod;
  p[1] = (-inv3 + (n + 2) % mod * inv2) % mod;
  p[0] = (-s3(n + 2) * inv3 + (n + 2) % mod * inv2 % mod * s2(n + 1)) % mod;
  ll s = eval(p, 1);
  for (ll x = 1; x * x <= n; ++x) {
    s = (s + 4 * eval(p, x * x % mod)) % mod;
  }
  vvl pws(4, vl(1000003));
  for (int i = 0; i < pws.size(); ++i) {
    for (ll j = 1; j < pws[i].size(); ++j) {
      ll j2 = j * j % mod;
      ll add = 1;
      for (int t = 0; t < i; ++t) add = add * j2 % mod;
      pws[i][j] = (pws[i][j-1] + add) % mod;
    }
  }
  ll y = sqrt(n) + 2;
  for (ll x = 1; x * x < n; ++x) {
    while (x * x + y * y > n) --y;
    ll x2 = x * x % mod;
    ll s1 = 0;
    s1 = (s1 + y * p[0]) % mod;
    s1 = (s1 + (x2 * y % mod + pws[1][y]) * p[1]) % mod;
    s1 = (s1 + (x2 * x2 % mod * y % mod + 2 * x2 * pws[1][y] % mod + pws[2][y]) * p[2]) % mod;
    s1 = (s1 + (x2 * x2 % mod * x2 % mod * y % mod + 3 * x2 * x2 % mod * pws[1][y] % mod + 3 * x2 * pws[2][y] % mod + pws[3][y]) * p[3]) % mod;
    //s1 = 0; for (int i = 1; i <= y; ++i) s1 = (s1 + eval(p, x2 + i * i)) % mod;
    s = (s + 4 * s1) % mod;
  }
/*  vl res(n + 1);
  for (int t = 1; t <= n; ++t) {
    res[t] = eval(p, t);
  }
  res[0] = res[1];
  for (int x = 1; x <= 1000; ++x) for (int y = 1; y <= 1000; ++y) if (x * x + y * y <= n) {
    s += 4 * res[x * x + y * y];
  }*/
  cout << (s % mod + mod) % mod << endl;
  return 0;
}