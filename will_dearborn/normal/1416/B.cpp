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
  for (int test = 0; test < T; ++test) {
    int n;
    cin >> n;
    vi a(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n) {
      cout << -1 << '\n';
      continue;
    }
    s /= n;
    vector<array<int, 3>> v;
    for (int i = 1; i < n; ++i) {
      int m = i + 1;
      if (a[i] % m) {
        int x = m - a[i] % m;
        assert(a[0] >= x);
        a[i] += x;
        a[0] -= x;
        v.push_back({0, i, x});
      }
      assert(a[i] % m == 0);
      if (a[i]) {
        int x = a[i] / m;
        a[i] -= x * m;
        a[0] += x * m;
        v.push_back({i, 0, x});
      }
      assert(a[i] == 0);
    }
    for (int i = 1; i < n; ++i) {
      v.push_back({0, i, s});
      a[0] -= s;
    }
    assert(a[0] == s);
/*    vii ts;
    for (int i = 1; i < n; ++i) {
      int m = i + 1;
      if (a[i] >= m) {
        v.push_back({i, 0, a[i] / m});
        a[0] += a[i] / m * m;
        a[i] %= m;
      }
      ts.emplace_back(m - a[i], i);
    }
    sort(ts.begin(), ts.end());
    int last = 0;
    for (pii p : ts) {
      if (p.first > a[last]) {
        break;
      }

    }*/
    cout << v.size() << '\n';
    for (auto x : v) cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] << '\n';
  }
  return 0;
}