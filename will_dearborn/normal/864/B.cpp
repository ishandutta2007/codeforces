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
  string s;
  cin >> n >> s;
  int res = 0, cur = 0;
  vi c(256);
  s += 'A';
  for (int i = 0; i < s.size(); ++i) {
    if (islower(s[i])) {
      if (!c[s[i]]) ++cur;
      c[s[i]]++;
    } else {
      res = max(res, cur);
      cur = 0;
      c.assign(c.size(), 0);
    }
  }
  cout << res << endl;
  return 0;
}