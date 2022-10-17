#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 2e3 + 10;
int d1[N][N], d2[N][N], a[N][N];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, w;
  cin >> n >> m >> w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      d1[i][j] = d2[i][j] = 1e18;
    }
  }
  auto good = [&](pair<int, int> cell) {
    return cell.first >= 1 && cell.first <= n && cell.second >= 1 && cell.second <= m;
  };
  const vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  queue<pair<int, int>> q;
  q.push({1, 1});
  d1[1][1] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (auto it : delta) {
      pair<int, int> to = {cur.first + it.first, cur.second + it.second};
      if (good(to) && a[to.first][to.second] >= 0 && d1[to.first][to.second] == 1e18) {
        d1[to.first][to.second] = d1[cur.first][cur.second] + 1;
        q.push(to);
      }
    }
  }
  q.push({n, m});
  d2[n][m] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (auto it : delta) {
      pair<int, int> to = {cur.first + it.first, cur.second + it.second};
      if (good(to) && a[to.first][to.second] >= 0 && d2[to.first][to.second] == 1e18) {
        d2[to.first][to.second] = d2[cur.first][cur.second] + 1;
        q.push(to);
      }
    }
  }
  int ans = 1e18;
  if (d1[n][m] != 1e18) {
    ans = d1[n][m] * w;
  }
  int mn1 = 1e18, mn2 = 1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > 0) {
        if (d1[i][j] < 1e18) {
          mn1 = min(mn1, d1[i][j] * w + a[i][j]);
        }
        if (d2[i][j] < 1e18) {
          mn2 = min(mn2, d2[i][j] * w + a[i][j]);
        }
      }
    }
  }
  ans = min(ans, mn1 + mn2);
  cout << (ans == 1e18 ? -1 : ans) << '\n';
}