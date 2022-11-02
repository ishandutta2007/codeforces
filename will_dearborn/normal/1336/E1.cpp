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

void add(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}

int d[2][36][1 << 15];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m0;
  cin >> n >> m0;
  vl a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int it = 0;
  vi v;
  for (int j = 0; j < m0; ++j) {
    ll B = 1LL << j;
    for (int i = it; i < n; ++i) if (a[i] & B) {
      swap(a[i], a[it]);
      break;
    }
    if ((it < n) && (a[it] & B)) {
      for (int i = 0; i < n; ++i) if (i != it) if (a[i] & B) {
        a[i] ^= a[it];
      }
      ++it;
    } else {
      v.push_back(j);
    }
  }
  ll mul = 1;
  int m = it;
  for (int i = 0; i < n - m; ++i) mul = mul * 2 % mod;
  vi res(m0 + 1);
  if (m <= 20) {
    vl d(1 << m);
    for (int mask = 0; mask < d.size(); ++mask) {
      for (int i = 0; i < m; ++i) if (mask & (1 << i)) {
        d[mask] = d[mask ^ (1 << i)] ^ a[i];
        break;
      }
      add(res[__builtin_popcountll(d[mask])], 1);
    }
  } else {
    vi b(m);
    int k = v.size();
    for (int i = 0; i < m; ++i) for (int j = 0; j < k; ++j) if (a[i] & (1LL << v[j])) {
      b[i] |= 1 << j;
    }
    //assert(0);
    assert(v.size() <= 15);
    d[0][0][0] = 1;
    for (int t = 0; t < m; ++t) {
      int tt = t % 2;
      for (int c = 0; c <= t; ++c) for (int mask = 0; mask < (1 << k); ++mask) {
        d[1-tt][c][mask] = d[tt][c][mask];
      }
      for (int c = 0; c <= t; ++c) for (int mask = 0; mask < (1 << k); ++mask) {
        add(d[1-tt][c + 1][mask ^ b[t]], d[tt][c][mask]);
      }
    }
    int tt = m % 2;
    for (int mask = 0; mask < (1 << k); ++mask) {
      int bc = __builtin_popcount(mask);
      for (int i = 0; i <= m; ++i) {
        add(res[i + bc], d[tt][i][mask]);
      }
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    res[i] = res[i] % mod * mul % mod;
    cout << res[i] << ' ';
  }
  return 0;
}