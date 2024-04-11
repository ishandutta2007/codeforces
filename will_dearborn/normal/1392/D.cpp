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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    if (s == string(n, 'L') || s == string(n, 'R')) {
      res = (n + 2) / 3;
    } else {
      int it = 0;
      while (s[it] == s[0]) ++it;
      s = s.substr(it) + s.substr(0, it);
      assert((int)s.size() == n && s[0] != s[n - 1]);
      vi v(1, 1);
      for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) ++v.back();
        else v.push_back(1);
      }
      for (ll x : v) {
        res += x / 3;
      }
    }
    cout << res << '\n';
  }
  return 0;
}