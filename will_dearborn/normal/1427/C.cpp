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
  int r, n;
  cin >> r >> n;
  vi d(n+1, -1e9), t(n+1), x(n+1), y(n+1), ma(n + 1);
  d[0] = 0;
  t[0] = 0;
  x[0] = 1;
  y[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
    for (int j = i - 1; j >= 0; --j) {
      int dd = t[i] - t[j];
      if (dd >= 2 * r) {
        d[i] = max(d[i], 1 + ma[j]);
        break;
      }
      if (dd >= abs(x[i] - x[j]) + abs(y[i] - y[j])) d[i] = max(d[i], 1 + d[j]);
    }
    ma[i] = max(ma[i - 1], d[i]);
  }
  cout << ma.back() << endl;
  return 0;
}