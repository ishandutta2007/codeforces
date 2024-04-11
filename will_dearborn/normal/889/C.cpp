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

ll inv(ll x) {
  return mpow(x, mod - 2);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 0 << endl; return 0;
  }
  vl fac(n + 1, 1), f(n), s(n + 1);
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i-1] * i % mod;
  f[0] = 1;
  f[1] = 1;
  s[1] = 1;
  s[2] = 2;
  for (int i = 2; i < f.size(); ++i) {
    f[i] = inv(i) * (s[i] - s[max(0, i - k)]) % mod;
    s[i+1] = (s[i] + f[i]) % mod;
  }
  ll res = (fac[n] - s[n] * fac[n-1]) % mod;
  cout << (res + mod) % mod << endl;
  return 0;
}