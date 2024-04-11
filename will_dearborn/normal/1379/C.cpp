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
    ll n, m;
    cin >> n >> m;
    vi a(m), b(m);
    vector<array<ll, 3>> ts;
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
      ts.push_back({a[i], 1, i});
      ts.push_back({b[i], 0, i});
    }
    sort(ts.rbegin(), ts.rend());
    ll res = 0;
    vi used(m);
    ll sum = 0;
    for (auto p : ts) if (n) {
      if (p[1] == 1) {
        --n;
        sum += p[0];
        res = max(res, sum);
        used[p[2]] = 1;
      } else {
        if (used[p[2]]) {
          res = max(res, sum + p[0] * n);
          break;
        } else {
          res = max(res, sum + a[p[2]] + p[0] * (n - 1));
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}