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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  int s = n - 1;
  vi v(1, n);
  for (int t = 0; t < k - 1; ++t) {
    vi nv = v;
    for (int i = 0; i < v.size(); ++i) nv[i] = -v[i];
    nv.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      nv[i + 1] = (nv[i + 1] + v[i]) % mod;
    }
    v.swap(nv);
    for (int i = 0; i < v.size(); ++i) {
      v[i] = v[i] * (ll)(i + s) % mod;
    }
    --s;
//    cerr << s << endl; for (auto x : v) cerr << x << ' '; cerr << endl;
  }
  ll res = 0, pw = mpow(2, max(s, 0));
  for (int i = max(0, -s); i < v.size(); ++i) {
    res = (res + pw * v[i]) % mod;
    pw = pw * 2 % mod;
  }
  cout << (res + mod) % mod << endl;
  return 0;
}