#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int N = 5010;
int dp[N][N][2];

void source() {
  int n;
  cin >> n;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      dp[i][j][0] = dp[i][j][1] = INF;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i][0] = dp[i][i][1] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      dp[l][r][0] = min(dp[l + 1][r][0] + (c[l] != c[l + 1]), dp[l + 1][r][1] + (c[l] != c[r]));
      dp[l][r][1] = min(dp[l][r - 1][0] + (c[l] != c[r]), dp[l][r - 1][1] + (c[r - 1] != c[r]));
    }
  }
  cout << min(dp[1][n][0], dp[1][n][1]);
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}