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

int c[26][5005][26];

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  s += s;
  vi cnt(26);
  for (int i = 0; i < n; ++i) {
    cnt[s[i]-'a']++;
    for (int j = i; j < i + n; ++j) {
      c[s[i]-'a'][j-i][s[j]-'a']++;
    }
  }
  double res = 0;
  for (int a = 0; a < 26; ++a) if (cnt[a]) {
    if (cnt[a] == 1) {
      res += 1. / n;
      continue;
    }
    double ma = 0;
    for (int j = 1; j < n; ++j) {
      double cur = 0;
      for (int b = 0; b < 26; ++b) if (c[a][j][b] == 1) cur += 1;
      ma = max(ma, cur / n);
    }
    res += ma;
  }
  printf("%.10lf\n", res);
  return 0;
}