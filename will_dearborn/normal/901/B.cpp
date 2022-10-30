#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

ll mpow(ll x, ll n, int mod) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x, int mod) {
  return mpow(x, mod - 2, mod);
}

void out(const vl & a) {
  cout << a.size() - 1 << endl;
  for (ll x : a) cout << x << ' ';
  cout << endl;
}

int run(vl a, vl b, int p) {
  int it = 0;
  while (b != vl(1, 0)) {
    assert(a.back() && b.back());
    while (a.size() >= b.size() && a != vl(1, 0)) {
      ll mul = a.back() * inv(b.back(), p) % p;
      int shift = a.size() - b.size();
      for (int i = 0; i < b.size(); ++i) {
        a[i+shift] = (a[i+shift] - mul * b[i]) % p;
      }
      while (a.size() > 1 && a.back() == 0) a.pop_back();
    }
    a.swap(b);
    ++it;
  }
  return it;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
/*  vl b(n+1);
  b[n] = 1;
  vl a(2, 1);
  if (n == 1) a.assign(1, 1);*/
/*  vl a(1, 1), b(2);
  b[1] = 1;
  for (int t = 1; t < n; ++t) {
    while (a.size() < b.size() + 1) a.push_back(0);
    for (int i = 0; i < b.size(); ++i) {
      int zn = t % 2 ? -1 : 1;
      a[i+1] += zn * b[i];
    }
    a.swap(b);
  }*/
  vl b(n+1, 1), a(n, 1);
  while (1) {
    for (int i = 0; i + 1 < a.size(); ++i) a[i] = rand() % 3 - 1;
    for (int i = 0; i + 1 < b.size(); ++i) b[i] = rand() % 3 - 1;
    if (run(b, a, mod1) == n && run(b, a, mod2) == n) {
      out(b);
      out(a);
      break;
    }
  }
  return 0;
}