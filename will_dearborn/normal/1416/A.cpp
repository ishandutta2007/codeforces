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
    map<int, vi> w;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      w[a[i]].push_back(i);
    }
    vi res(n + 1, 1e9);
    for (auto& p : w) {
      auto& v = p.second;
      int ma = max(v[0] + 1, n - v.back());
      for (int i = 0; i + 1 < v.size(); ++i) ma = max(ma, v[i + 1] - v[i]);
      res[ma] = min(res[ma], p.first);
    }
    for (int i = 1; i + 1 < res.size(); ++i) res[i + 1] = min(res[i + 1], res[i]);
    for (int i = 1; i <= n; ++i) {
      if (res[i] > n) res[i] = -1;
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}