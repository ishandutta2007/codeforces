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
  int n, p;
  cin >> n >> p;
  for (int k = 1; k <= 100; ++k) {
    int m = n - p * k;
    int t = __builtin_popcount(m);
    if (m >= k && t <= k) {
      cout << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}