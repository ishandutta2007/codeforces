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

/*int pref[2][3005], suf[2][3005], seg[2][3005];
int m;

int& get(int t, int i, int j) {
  if (i == 0) return pref[t][j];
  if (j == m-1) return suf[t][i];
  return seg[t][i];
}*/

void add(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  reverse(s.begin(), s.end());
  vi d(n + 1, 0);
  d[0] = 1;
  int res = 0;
  for (int x = 0; x < n; ++x) {
    vi nd(d.size());
    nd[m] = 2 * d[m] % mod;
    for (int i = 0; i < m; ++i) if (d[i]) {
      if (t[i] == s[x]) add(nd[i + 1], d[i]);
      int pos = n - (x - i) - 1;
      if (pos >= m || t[pos] == s[x]) {
        add(nd[i], d[i]);
      }
    }
    if (x < n - m) add(nd[0], 1);
    d.swap(nd);
  }
  for (int i = 0; i < d.size(); ++i) add(res, d[i]);
  cout << res << endl;
  return 0;
}