#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vl c(26);
  vvl d(26, vl(26));
  for (int i = 0; i < n; ++i) {
    int x = s[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      d[j][x] += c[j];
    }
    ++c[x];
  }
  ll ma = 0;
  for (ll x : c) ma = max(ma, x);
  for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) ma = max(ma, d[i][j]);
  cout << ma << endl;
  return 0;
}