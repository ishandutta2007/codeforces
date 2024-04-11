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
  vvl a(n, vl(n));
  for (int s = 1; s <= 2 * n - 2; ++s) {
    for (int i = 0; i < n; ++i) {
      int j = s - i;
      if (j < 0 || j >= n) continue;
      if (i % 2) a[i][j] = 1LL << (s - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << ' ';
      assert(a[i][j] < 1e16);
    }
    cout << endl;
  }
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll x;
    cin >> x;
    vii v(2 * n - 1);
    for (int s = 0; s + 1 < v.size(); ++s) {
      v[s + 1] = v[s];
      if ((bool)(v[s].first % 2) != (bool)(x & (1LL << s))) {
        ++v[s + 1].first;
      } else {
        ++v[s + 1].second;
      }
    }
    assert(v.back() == pii(n - 1, n - 1));
    for (auto p : v) {
      cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
  }
  return 0;
}