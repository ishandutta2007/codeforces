#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
const int N = 510;
const int K = 21;
const int INF = 1e9 + 10;
int l[N][N], r[N][N], d[N][N], up[N][N], dp[N][N][K];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  if (k & 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
    }
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      cin >> r[i][j];
      l[i][j + 1] = r[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> d[i][j];
      up[i + 1][j] = d[i][j];
    }
  }
  auto is_correct = [&](int a, int b) {
    return a >= 1 && b >= 1 && a <= n && b <= m;
  };
  auto get_cost = [&](int a, int b, int a2, int b2) {
    if (a2 == a + 1) {
      return d[a][b];
    }
    if (a2 == a - 1) {
      return up[a][b];
    }
    if (b2 == b + 1) {
      return r[a][b];
    }
    if (b2 == b - 1) {
      return l[a][b];
    }
    return INF;
  };
  vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  for (int p = 2; p <= k; p += 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j][p] = INF;
        for (auto it : delta) {
          int i2 = i + it.F, j2 = j + it.S;
          if (is_correct(i2, j2)) {
            dp[i][j][p] = min(dp[i][j][p], 2 * get_cost(i, j, i2, j2) + dp[i2][j2][p - 2]);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << dp[i][j][k] << ' ';
    }
    cout << '\n';
  }  
}