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
  vi erat(1e6 + 5);
  for (int i = 0; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i < erat.size(); ++i) if (erat[i] == i) {
    for (int j = 2 * i; j < erat.size(); j += i) erat[j] = i;
  }
  int n;
  cin >> n;
  if (erat[n] == n) {
    cout << n << endl;
    return 0;
  }
  int res = n - erat[n] + 1;
  for (int i = n - erat[n] + 1; i <= n; ++i) {
    if (erat[i] != i) {
      res = min(res, i - erat[i] + 1);
    }
  }
  cout << res << endl;
  return 0;
}