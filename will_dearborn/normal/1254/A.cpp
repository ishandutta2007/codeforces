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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m, k;
    cin >> n >> m >> k;
    vs s(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < m; ++j) c += s[i][j] == 'R';
    }
    vector<char> v;
    for (int i = 0; i < 10; ++i) v.push_back('0' + i);
    for (int i = 0; i < 26; ++i) {
      v.push_back('a' + i);
      v.push_back('A' + i);
    }
    vs res(n, string(m, 'a'));
    int it = 0, x = 0;
    vvi ord(2, vi(m));
    for (int i = 0; i < m; ++i) {
      ord[0][i] = i;
      ord[1][i] = m - i - 1;
    }
    for (int i = 0; i < n; ++i) for (int j : ord[i%2]) {
      res[i][j] = v[it];
      x += s[i][j] == 'R';
      if (x >= c / (k - it) && it + 1 < k) {
        ++it;
        c -= x;
        x = 0;
      }
    }
    for (int i = 0; i < n; ++i) cout << res[i] << endl;
  }
  return 0;
}