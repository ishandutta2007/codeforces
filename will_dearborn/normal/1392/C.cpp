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
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll res = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) res += a[i] - a[i + 1];
    }
    cout << res << '\n';
  }
  return 0;
}