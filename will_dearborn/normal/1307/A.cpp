#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, d;
    cin >> n >> d;
    vi a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i == 0) res += a[i];
      else {
        int x = min(a[i], d / i);
        res += x;
        d -= i * x;
      }
    }
    cout << res << '\n';
  }
  return 0;
}