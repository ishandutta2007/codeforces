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
  vi v(n), t(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  vl s(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    s[i + 1] = s[i] + t[i];
  }
  vl res(n);
  vvi d(n + 1);
  for (int i = 0; i < n; ++i) {
    int l = i-1, r = n;
    while (r - l > 1) {
      int x = (l + r) / 2;
      if (s[x + 1] - s[i] >= v[i]) {
        r = x;
      } else l = x;
    }
    d[r].push_back(i);
  }
  ll c = 0;
  for (int i = 0; i < n; ++i) {
    ++c;
    c -= d[i].size();
    for (int x : d[i]) {
      res[i] += v[x] - (s[i] - s[x]);
    }
    res[i] += c * t[i];
  }
  for (int i = 0; i < n; ++i) cout << res[i] << ' ';
  return 0;
}