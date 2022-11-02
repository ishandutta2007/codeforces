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

ll eval(ll k, ll a, ll b, ll c, ll d) {
  return a * k - k * (k - 1) / 2 * b * d;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b*c < a) {
      cout << "-1\n";
      continue;
    }
    ll k0 = c / d + 1;
    ll res = max(a, eval(k0, a, b, c, d));
    ll k1 = (2 * a + b * d) / (2 * b * d);
    if (k1 < k0) {
      res = max(res, eval(k1, a, b, c, d));
      res = max(res, eval(k1 + 1, a, b, c, d));
    }
    cout << res << '\n';
  }
  return 0;
}