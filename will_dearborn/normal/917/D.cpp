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

array<array<int, 100>, 100> a;

int det(int n) {
  ll res = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) if (a[j][i]) {
      a[i].swap(a[j]); break;
    }
    if (!a[i][i]) return 0;
    res = res * a[i][i] % mod;
    ll mul = mpow(a[i][i], mod-2);
//    cerr << n << ' ' << res << ' ' << a[i][i] << ' ' << mul << endl;
    for (int j = i; j < n; ++j) {
      a[i][j] = a[i][j] * mul % mod;
    }
    for (int j = i + 1; j < n; ++j) if (a[j][i]) {
      ll mul = a[j][i];
      for (int l = i; l < n; ++l) {
        a[j][l] = (a[j][l] - a[i][l] * mul) % mod;
      }
    }
  }
  if (res < 0) res += mod;
  return res;
}

vi mul(vi x, vi y) {
  vi res(x.size() + y.size() - 1);
  for (int i = 0; i < x.size(); ++i) for (int j = 0; j < y.size(); ++j) {
    res[i+j] = (res[i+j] + x[i] * (ll)y[j]) % mod;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii e;
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    --a; --b;
    e.emplace_back(a, b);
  }
  vi v(n);
  for (int x = 0; x < n; ++x) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) a[i][j] = -1;
      a[i][i] = n-1;
    }
    for (pii p : e) {
      a[p.first][p.first] += x-1;
      if (p.second < n-1) {
        a[p.second][p.first] -= x-1;
        a[p.first][p.second] -= x-1;
        a[p.second][p.second] += x-1;
      }
    }
/*    for (int i = 0; i < n-1; ++i) {
      for (int j = 0; j < n-1; ++j) cerr << a[i][j] << ' '; cerr << endl;
    }*/
    v[x] = det(n-1);
//    cerr << x << ' ' << v[x] << endl;
  }
  vi p(n);
  for (int i = 0; i < n; ++i) {
    vi x(1, v[i]);
    ll d = 1;
    for (int j = 0; j < n; ++j) if (i != j) {
      d = d * (i - j) % mod;
    }
    x[0] = x[0] * mpow(d, mod - 2) % mod;
    for (int j = 0; j < n; ++j) if (i != j) {
      vi y(2, 1);
      y[0] = -j;
      x = mul(x, y);
    }
    for (int i = 0; i < p.size(); ++i) {
      p[i] = (p[i] + x[i]) % mod;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] < 0) p[i] += mod;
    cout << p[i] << ' ';
  }
  cout << endl;
  return 0;
}