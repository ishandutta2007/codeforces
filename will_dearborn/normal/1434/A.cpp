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
  vi a(6);
  for (int i = 0; i < 6; ++i) cin >> a[i];
  int n;
  cin >> n;
  vi b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int res = b.back() - b[0];
  for (int t1 = 0; t1 < 6; ++t1) for (int t2 = 0; t2 < n; ++t2) {
    int mi = b[t2] - a[t1];
    bool fail = 0;
    int ma = max(mi, b.back() - a.back());
    for (int i = 0; i < a.size(); ++i) {
      int j = lower_bound(b.begin(), b.end(), a[i] + mi) - b.begin();
      if (j < b.size()) ma = max(ma, b[j] - a[i]);
      if (i == 0) {
        if (j != 0) fail = 1;
      } else {
        if (j > 0) {
          ma = max(ma, b[j - 1] - a[i - 1]);
        }
      }
    }
    if (fail) continue;
    else res = min(res, ma - mi);
  }
  cout << res << endl;
  return 0;
}