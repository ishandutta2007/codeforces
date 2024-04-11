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
    vi a(n);
    int ma = -1e9;
    int d = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ma = max(a[i], ma);
      d = max(ma - a[i], d);
    }
    int ans = 0;
    if (d) for (int b = 0; b <= 31; ++b) {
      if (d <= (1LL << b) - 1) {
        ans = b;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}