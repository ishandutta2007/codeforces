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
const int N = 41;
int a[3][3], dp[N][3][3];

signed main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      dp[1][i][j] = a[i][j];
    }
  }
  for (int iter = 0; iter < 3; iter++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int p = 0;
        while (p == j || p == k) {
          p++;
        }
        dp[1][j][k] = min(dp[1][j][k], dp[1][j][p] + dp[1][p][k]);
      }
    }
  }
  /*for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      cout << dp[1][j][k] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';*/
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) {
          dp[i][j][k] = 0;
          continue;
        }
        int p = 0;
        while (p == j || p == k) {
          p++;
        }
        dp[i][j][k] = min(dp[i - 1][j][p] + a[j][k] + dp[i - 1][p][k], dp[i - 1][j][k] + a[j][p] + dp[i - 1][k][j] + a[p][k] + dp[i - 1][j][k]);
      }
    }
    for (int iter = 0; iter < 3; iter++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          int p = 0;
          while (p == j || p == k) {
            p++;
          }
          dp[i][j][k] = min(dp[i][j][k], dp[i][j][p] + dp[i][p][k]);
        }
      }
    }
    /*for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cout << dp[i][j][k] << ' ';
      }
      cout << '\n';
    }
    cout << '\n';*/
  }
  cout << dp[n][0][2] << '\n';
}