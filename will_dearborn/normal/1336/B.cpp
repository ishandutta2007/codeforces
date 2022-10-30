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

ll p2(ll x) {
  return x * x;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    vvi v(3);
    vi l(3);
    for (int i = 0; i < 3; ++i) {
      cin >> l[i];
    }
    for (int i = 0; i < 3; ++i) {
      v[i].resize(l[i]);
      for (int j = 0; j < l[i]; ++j) {
        cin >> v[i][j];
      }
      sort(v[i].begin(), v[i].end());
    }
    ll mi = 4e18;
    for (int x = 0; x < 3; ++x) for (int y : {0, 1}) {
      int x1 = (x + 2 - y) % 3, x2 = (x + y + 1) % 3;
      for (int a : v[x]) {
        auto it1 = lower_bound(v[x1].begin(), v[x1].end(), a);
        auto it2 = lower_bound(v[x2].begin(), v[x2].end(), a);
        if (it1 != v[x1].end() && it2 != v[x2].end()) {
          mi = min(mi, p2(a - *it1) + p2(a - *it2) + p2(*it1 - *it2));
          if (*it1 < *it2) {
            auto it = lower_bound(v[x1].begin(), v[x1].end(), (a + *it2) / 2);
            if (it != v[x1].end()) mi = min(mi, p2(a - *it) + p2(a - *it2) + p2(*it - *it2));
            if (it != v[x1].begin()) {
              --it;
              mi = min(mi, p2(a - *it) + p2(a - *it2) + p2(*it - *it2));
            }
          } 
        }
      }
    }
    cout << mi << '\n';
  }
  return 0;
}