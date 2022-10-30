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
  vi a(n), b(n);
  vi was(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    was[a[i]] = 1;
  }
  int s = 1;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] == s) {
      ++s;
    } else {
      s = 1;
    }
  }
  int res = 0;
  while (s <= n) {
    if (was[s]) {
      ++s;
      b.push_back(s);
    } else {
      b.push_back(0);
    }
    if (b[res] == 1 && s > 1) {
      res = n + res + 1;
      break;
    }
    was[b[res]] = 1;
    ++res;
  }
  cout << res << endl;
  return 0;
}