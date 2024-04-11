#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;
const int N=  3e5 + 10;
const int M = 11;
int a[N];
int dp[N][M];
signed main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = -BINF;
    }
  }
  dp[0][0] = 0;
  for (int  i =0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] == -BINF) {
        continue;
      }
      int to = (j + 1) % m, add = (j == 0 ? k : 0);
      dp[i + 1][to] = max(dp[i + 1][to], dp[i][j] + a[i] - add);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j< m; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}