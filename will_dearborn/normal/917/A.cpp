#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

vector<vector<char>> f(string s) {
  int n = s.size();
  vector<vector<char>> d(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] != ')') ++sum;
      else --sum;
      if (sum < 0) break;
      d[i][j] = 1;
    }
  }
  return d;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  vector<vector<char>> d = f(s);
  int n = s.size();
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') s[i] = ')';
    else if (s[i] == ')') s[i] = '(';
  }
  vector<vector<char>> d1 = f(s);
  int res = 0;
  for (int i = 0; i < s.size(); ++i) for (int j = i + 1; j < s.size(); j += 2) {
    if (d[i][j] && d1[n - 1 - j][n - i - 1]) ++res;
  }
  cout << res << endl;
  return 0;
}