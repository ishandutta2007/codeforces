/**
 *    author:  tourist
 *    created: 10.10.2021 12:18:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += 1;
      { // right
        int nr = m - 1 - j;
        int nd = n - 1 - i;
        nr = min(nr, nd + 1);
        nd = min(nd, nr);
        ans += nr + nd;
      }
      { // down
        int nr = m - 1 - j;
        int nd = n - 1 - i;
        nd = min(nd, nr + 1);
        nr = min(nr, nd);
        ans += nr + nd;
      }
    }
  }
  vector<vector<int>> a(n, vector<int>(m));
  auto Go = [&](int i, int j, int di, int dj) {
    int cc = 0;
    while (true) {
      i += di;
      j += dj;
      if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 1) {
        break;
      }
      cc += 1;
      swap(di, dj);
    }
    return cc;
  };
  while (q--) {
    int i, j;
    cin >> i >> j;
    --i; --j;
    {
      int x = Go(i, j, -1, 0);
      int y = Go(i, j, 0, 1);
      ans += (a[i][j] == 1 ? 1 : -1) * ((x + 1) * (y + 1) - 1);
    }
    {
      int x = Go(i, j, 0, -1);
      int y = Go(i, j, 1, 0);
      ans += (a[i][j] == 1 ? 1 : -1) * ((x + 1) * (y + 1) - 1);
    }
    ans += (a[i][j] == 1 ? 1 : -1);
    a[i][j] ^= 1;
    cout << ans << '\n';
  }
  return 0;
}