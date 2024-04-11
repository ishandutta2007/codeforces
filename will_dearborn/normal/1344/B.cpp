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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
vvi was;
vs s;

void dfs(int i, int j) {
  if (was[i][j]) return;
  was[i][j] = 1;
  for (int d = 0; d < 4; ++d) {
    int ni = i + dx[d], nj = j + dy[d];
    if (ni >= 0 && nj >= 0 && ni < n && nj < m && s[i][j] == '#') dfs(ni, nj);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n >> m;
  s.resize(n);
  bool fail = 0;
  int r0 = 0, c0 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int t = 0;
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') {
        if (t == 1) ++t;
      } else {
        if (t == 0) ++t;
        else if (t == 2) fail = 1;
      }
    }
    if (t == 0) ++r0;
  }
  for (int j = 0; j < m; ++j) {
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == '.') {
        if (t == 1) ++t;
      } else {
        if (t == 0) ++t;
        else if (t == 2) fail = 1;
      }
    }
    if (t == 0) ++c0;
  }
  if ((c0 == 0) != (r0 == 0)) fail = 1;
  if (fail) {
    cout << -1 << endl;
    return 0;
  }
  was.assign(n, vi(m));
  int res = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (!was[i][j] && s[i][j] == '#') {
    ++res;
    dfs(i, j);
  }
  cout << res << endl;
  return 0;
}