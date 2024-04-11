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
  ll k, d, t;
  cin >> k >> d >> t;
  t *= 2;
  ll T = (k + d - 1) / d * d;
  ll T1 = T - k;
  ll g = 2 * k + T1;
  ll res = t / g * 2 * T;
  t %= g;
//  cerr << t << ' ' << g << ' ' << T << ' ' << res << endl;
  if (t <= 2 * k) {
    res += t;
  } else {
    res += 2 * k + 2 * (t - 2 * k);
  }
  cout << res / 2 << "." << 5 * (res % 2) << endl;
  return 0;
}