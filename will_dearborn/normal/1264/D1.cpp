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
const int mod = 998244353;

vl pw;

vvl f(string s) {
  int n = s.size();
  vvl d(n + 1, vl(n / 2 + 1));
  d[0][0] = 1;
  vl sum(d[0].size());
  sum[0] = 1;
  int c = 0;
  for (int i = 0; i < n; ++i) c += s[i] == '?';
  for (int i = 0; i < n; ++i) {
    c -= s[i] == '?';
    if (s[i] == '?' || s[i] == '(') {
      for (int j = 0; j + 1 < sum.size(); ++j) {
        d[i + 1][j + 1] = sum[j] % mod;
//        if (sum[j]) cerr << i << ' ' << j + 1 << endl;
      }
    }
    if (s[i] == '(') for (int i = 0; i + 1 < sum.size(); ++i) sum[i] = 0;
    for (int j = 0; j < sum.size(); ++j) {
      sum[j] = (sum[j] + d[i + 1][j]) % mod;
    }
  }
  return d;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  pw.assign(n + 1, 1);
  for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i - 1] * 2 % mod;
  vvl l = f(s);
  string s1 = s;
  reverse(s1.begin(), s1.end());
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == ')') s1[i] = '(';
    else if (s1[i] == '(') s1[i] = ')';
  }
  vvl r = f(s1);
  ll res = 0;
  vl sum = l[0];
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < sum.size(); ++j) {
//      if (sum[j] && r[n-i][j]) cerr << i << ' ' << j << endl;
      res = (res + sum[j] % mod * r[n - i][j]) % mod;
    }
    for (int j = 0; j < sum.size(); ++j) {
      sum[j] = (sum[j] * (s[i] == '?' ? 2 : 1) + l[i + 1][j]) % mod;
    } 
  }
  cout << res << endl;
  return 0;
}