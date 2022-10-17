#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 51;
int dp[N][N][N][N], a[N][N];
int get_sum(int a1, int b1, int a2, int b2) {
  return a[a2][b2] + a[a1 - 1][b1 - 1] - a[a2][b1 - 1] - a[a1 - 1][b2];
}

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        a[i][j] = 1;
      }
      else {
        a[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i - 1][j];
    }
  }
  for (int len1 = 1; len1 <= n; len1++) {
    for (int len2 = 1; len2 <= n; len2++) {
      for (int i1 = 1; i1 + len1 - 1 <= n; i1++) {
        for (int j1 = 1; j1 + len2 - 1 <= n; j1++) {
          int i2 = i1 + len1 - 1, j2 = j1 + len2 - 1;
          if (get_sum(i1, j1, i2, j2) > 0) {
            dp[i1][j1][i2][j2] = max(len1, len2);
          }
          else {
            dp[i1][j1][i2][j2] = 0;
          }
          for (int k = i1; k < i2; k++) {
            dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], dp[i1][j1][k][j2] + dp[k + 1][j1][i2][j2]);
          }
          for (int k = j1; k < j2; k++) {
            dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], dp[i1][j1][i2][k] + dp[i1][k + 1][i2][j2]);
          }
        }
      }
    }
  }
  cout << dp[1][1][n][n] << '\n';
}