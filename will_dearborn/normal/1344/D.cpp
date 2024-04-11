#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll f(ll a, ll b) {
  //return b * (a - b * b);
  if (b == a) return -9e18;
  return a - 3 * b * b - 3 * b - 1;
}

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n = 1e5, k = 1e13;
  if (!DEBUG) cin >> n >> k;
  vl a(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) cin >> a[i];
    else a[i] = rand() % 1000000000 + 1;
  }
  ld l = -3e18, r = a[0];
  for (int it = 0; it < 100 && r - l > 1e-8; ++it) {
    ld t = (l + r) / 2;
//    cerr << l << ' ' << r << endl;
    double s = 0;
    for (int i = 0; i < n; ++i) {
      s += min(1. * a[i], sqrt(max(0., a[i] - (double)t) / 3.));
    }
    if (s >= k) {
      l = t;
    } else {
      r = t;
    }
  }
  vl b(n);
  ll rem = k;
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    b[i] = sqrtl(max((ld)0., a[i] - r) / 3.);
    b[i] = min(b[i], a[i]);
//    cerr << b[i] << endl;
    rem -= b[i];
    ts[i] = pii(f(a[i], b[i]), i);
  }
//  cerr << rem << endl;
  assert(rem >= 0 && rem <= n);
  sort(ts.rbegin(), ts.rend());
  for (int i = 0; i < rem; ++i) b[ts[i].second]++;
  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
  cout << endl;
  return 0;
}