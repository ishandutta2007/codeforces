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
    ll l, r, m;
    cin >> l >> r >> m;
    ll d = r - l;
    ll L = max(1LL, m - d), R = m + d;
    for (int a = l; a <= r; ++a) {
      int rem = (a - L % a) % a;
      if (L + rem <= R) {
        ll diff = L + rem - m;
        ll b = l, c = l;
        if (diff < 0) {
          c = l;
          b = c - diff;
        } else {
          b = l;
          c = l + diff;
        }
        cout << a << ' ' << b << ' ' << c << endl;
        break;
      }
    }
  }
  return 0;
}