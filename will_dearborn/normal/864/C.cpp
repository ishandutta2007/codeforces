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
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  if (b < a - f || (k > 1 && b < 2 * (a - f)) || (k > 2 && b < 2 * f) || b < f) {
    cout << -1 << endl;
    return 0;
  }
  int c = 0, cur = b;
  for (int i = 1; i <= k; ++i) {
    cur -= f;
    assert(cur >= 0);
    if (cur < a - f || (i < k && cur < 2 * (a - f))) {
      cur = b;
      ++c;
    }
    cur -= (a - f);
    assert(cur >= 0);
    f = a - f;
  }
  cout << c << endl;
  return 0;
}