#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

pii f(pii a, pii b) {
  return pii(a.first * b.first % mod, (b.first * a.second + b.second) % mod);
}

const int N = 1 << 18;
vii a(2 * N, pii(1, 0));

ll calc(int l, int r) {
  l += N;
  r += N;
  pii res(1, 0);
  vi L, R;
  while (l < r) {
    if (l & 1) {
      L.push_back(l);
      ++l;
    }
    if (r & 1) {
      R.push_back(r - 1);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  reverse(R.begin(), R.end());
  for (int p : L) {
    res = f(res, a[p]);
  }
  for (int p : R) {
    res = f(res, a[p]);
  }
  return res.second;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, q;
  cin >> n >> q;
  vl p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    ll p1 = 100 * mpow(p[i], mod - 2) % mod;
    a[N + i] = pii(p1, p1);
  }
  for (int i = N - 1; i > 0; --i) a[i] = f(a[2 * i], a[2 * i + 1]);
  vi w(n);
  w[0] = 1;
  set<int> was;
  was.insert(0);
  was.insert(n);
  ll res = calc(0, n);
  for (int t = 0; t < q; ++t) {
    int u;
    cin >> u; --u;
    if (w[u]) {
      w[u] = 0;
      was.erase(u);
      auto it = was.lower_bound(u);
      int r = *it;
      --it;
      int l = *it;
      res = (res + calc(l, r) - calc(l, u) - calc(u, r)) % mod;
    } else {
      w[u] = 1;
      auto it = was.lower_bound(u);
      int r = *it;
      --it;
      int l = *it;
      res = (res - calc(l, r) + calc(l, u) + calc(u, r)) % mod;
      was.insert(u);
    }
    cout << (res + mod) % mod << '\n';
  }
  return 0;
}