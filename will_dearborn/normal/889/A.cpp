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
  vi t(n), was(n + 2);
  int res = 1;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    res += was[t[i]];
    was[t[i]] = 1;
  }
  cout << res << endl;
  return 0;
}