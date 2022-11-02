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
const int mod = 1e9 + 7;
const ll M = 1e9;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 500;
  if (!DEBUG) cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n = 1000000 / T, p = 2;
    if (!DEBUG) cin >> n >> p;
    vl a(n);
    for (int i = 0; i < n; ++i) {
      if (!DEBUG) cin >> a[i];
      else a[i] = rand() % 1000000;
    }
    if (p == 1) {
      cout << n % 2 << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    ll c = 0;
    ll ans = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
//      cerr << a[i] << ' ' << c << endl;
      if (c > 0) --c;
      else c = 1;
      if (c > 0 && i && a[i - 1] < a[i]) {
        int cur = a[i];
        while (cur > a[i - 1] && c < M / p * p) {
          ll t = min(c, M / p);
          ans = (ans + (c - t) * mpow(p, cur)) % mod;
          c = t * p;
          --cur;
        }
        if (cur != a[i - 1]) {
          ans = (ans + c * mpow(p, cur)) % mod;
          ans = (ans - c * mpow(p, a[i - 1])) % mod;
        }
      } else if (i == 0) {
        ans = (ans + c * mpow(p, a[i])) % mod;
      }
    }
    cout << (ans + mod) % mod << '\n';
  }
  return 0;
}