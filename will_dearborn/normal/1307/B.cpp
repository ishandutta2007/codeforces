#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    ll res = 1e18;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == x) res = 1;
    }
    sort(a.rbegin(), a.rend());
    res = min(res, max(2LL, (x + a[0] - 1) / a[0]));
    cout << res << '\n';
  }
  return 0;
}