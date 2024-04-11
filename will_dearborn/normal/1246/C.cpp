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
const int mod = 1e9 + 7;

int d[2][2005][2005];
int a[2][2005][2005];

void add(int& x, int y) {
  x = (x + y) % mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vs s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  if (n + m == 2) {
    cout << 1 << endl;
    return 0;
  }
  vvi r(n, vi(m + 1)), c(m, vi(n + 1));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    r[i][j + 1] = r[i][j] + (int)(s[i][j] == 'R');
  }
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
    c[i][j + 1] = c[i][j] + (int)(s[j][i] == 'R');
  }
  a[0][0][0] = a[1][0][0] = 1;
  a[0][1][0] = -1;
  a[1][0][1] = -1;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    add(d[0][i][j], a[0][i][j]);
    add(d[1][i][j], a[1][i][j]);
    add(d[0][i + 1][j], d[0][i][j]);
    add(d[1][i][j + 1], d[1][i][j]);
    int len = m - j - 1, rem = r[i][m] - r[i][j + 1];
    add(a[1][i][j + 1], d[0][i][j]);
    add(a[1][i][j + 1 + len - rem], -d[0][i][j]);
    len = n - i - 1, rem = c[j][n] - c[j][i + 1];
    add(a[0][i + 1][j], d[1][i][j]);
    add(a[0][i + 1 + len - rem][j], -d[1][i][j]);
  }
  cout << (2LL * mod + d[0][n-1][m-1] + d[1][n-1][m-1]) % mod << endl;
  return 0;
}