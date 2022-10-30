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
    vii v(1, pii(0, 1));
    cin >> v[0].first;
    for (int i = 0; i < n - 1; ++i) {
      int t;
      cin >> t;
      if (v.back().first == t) ++v.back().second;
      else v.emplace_back(t, 1);
    }
    vi res(3);
    vi s(v.size() + 1);
    int ma = 0;
    for (int i = 0; i < v.size(); ++i) {
      s[i + 1] = s[i] + v[i].second;
      if (s[i + 1] * 2 <= n) ma = s[i + 1];
    }
    int it = 0;
    for (int i = 0; i < v.size(); ++i) {
      while (it < s.size() && s[it] <= 2 * s[i + 1]) ++it;
      if (it >= s.size()) break;
      if (s[i + 1] >= ma - s[it]) break;
      res = {s[i + 1], s[it] - s[i + 1], ma - s[it]};
      break;
    }
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
  }
  return 0;
}