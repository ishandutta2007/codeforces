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
  vl a(n), pw(n);
  vi c(100);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ll x = a[i];
    while (x % 2 == 0) {
      x /= 2;
      ++pw[i];
    }
    ++c[pw[i]];
  }
  int ma = 0, best = 0;
  for (int i = 0; i < c.size(); ++i) if (ma < c[i]) {
    ma = c[i];
    best = i;
  }
  cout << n - ma << endl;
  for (int i = 0; i < n; ++i) if (pw[i] != best) cout << a[i] << ' ';
  cout << endl;
  return 0;
}