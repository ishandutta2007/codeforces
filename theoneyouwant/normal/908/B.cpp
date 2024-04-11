#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
const int maxn = 55;
string s[maxn];
 
signed main() {
#ifdef LOCAL
  assert(freopen("test.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  int sx = -1, sy = -1;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S')
        sx = i, sy = j;
    }
  }
  string w;
  cin >> w;
  vector<int> p{0, 1, 2, 3};
  const int dx[] = {-1, 0, 1, 0};
  const int dy[] = {0, -1, 0, 1};
  int res = 0;
  do {
    int x = sx, y = sy;
    bool fail = false;
    for (auto c : w) {
      x += dx[p[c - '0']];
      y += dy[p[c - '0']];
      if (x >= n || x < 0 || y >= m || y < 0 || s[x][y] == '#') {
        fail = true;
        break;
      }
      if (s[x][y] == 'E')
        break;
    }
    if (!fail && s[x][y] == 'E') {
      ++res;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << res << '\n';
}