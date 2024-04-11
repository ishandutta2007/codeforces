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
  vi x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  int d = 0;
  for (int i = 0; i < n; ++i) {
    x[i] -= x.back();
    y[i] -= y.back();
    d = __gcd(d, abs(x[i]));
    d = __gcd(d, abs(y[i]));
  }
  vi v;
  for (int i = 0; i < n; ++i) {
    x[i] /= d;
    y[i] /= d;
    if ((x[i] + y[i] + 1) % 2 == 0) v.push_back(i);
  }
  if (v.empty()) {
    for (int i = 0; i < n; ++i) {
      if (x[i] % 2 && y[i] % 2) v.push_back(i);
    }
  }
  cout << v.size() << endl;
  for (int i : v) cout << i + 1 << ' ';
  return 0;
}