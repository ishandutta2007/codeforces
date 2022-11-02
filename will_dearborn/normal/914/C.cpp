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
const int mod = 1000000007;

int solve(string s, int k) {
  if (k == 0) {
    return 1;
  }
  --k;
  int n = s.size();
  vi d(n + 1);
  for (int i = 2; i < d.size(); ++i) {
    d[i] = 1 + d[__builtin_popcount(i)];
  }
  vi c(n + 1);
  int sum = 0;
  for (int t = 0; t < n; ++t) {
    for (int i = n; i > 0; --i) {
      c[i] = (c[i] + c[i-1]) % mod;
    }
    if (s[t] == '1') c[sum]++;
    sum += s[t] - '0';
  }
  c[sum]++;
  ll res = 0;
  for (int i = 1; i < d.size(); ++i) {
//    cerr << i << ' ' << d[i] << ' ' << c[i] << endl;
    if (d[i] == k) {
      res += c[i];
    }
  }
  if (k == 0) res--;
  return res % mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  cout << solve(s, k) << endl;
  return 0;
}