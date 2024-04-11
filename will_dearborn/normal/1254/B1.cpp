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
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  if (s == 1) {
    cout << -1 << endl;
    return 0;
  }
  ll res = 1e18;
  vl p;
  for (ll i = 2; i * i <= s; ++i) if (s % i == 0) {
    p.push_back(i);
    while (s % i == 0) s /= i;
  }
  if (s > 1) p.push_back(s);
  vl r(n);
  for (ll d : p) {
    ll cnt = 0;
    r = a;
    for (int i = 0; i + 1 < n; ++i) {
      if (r[i] > 0) r[i] %= d;
      if (r[i] >= 0 && r[i] * 2 <= d) {
        r[i + 1] += r[i];
        cnt += r[i];
      } else if (r[i] < 0) {
        cnt -= r[i];
        r[i + 1] += r[i];
      } else {
        cnt += d - r[i];
        r[i + 1] -= d - r[i];
      }
    }
    res = min(res, cnt);
  }
  cout << res << endl;
  return 0;
}