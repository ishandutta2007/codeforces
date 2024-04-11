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

const int N = 2010;
int dp[2 * N][N][2];
int a[2 *  N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i <= 2 * n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j][0] = dp[i][j][1] = 1e9;
      }
    }
    dp[1][1][0] = a[1];
    dp[1][0][1] = a[1];
    for (int i = 2; i <= 2 * n; i++) {
      for (int j = 0; j <= n; j++) {
        if (j) {
          if (a[i] > dp[i - 1][j - 1][1]) {
            dp[i][j][0] = min(dp[i][j][0], a[i]);
          }
          dp[i][j][0] = min(dp[i][j][0], max(dp[i - 1][j - 1][0], a[i]));
        }
        if (a[i] > dp[i - 1][j][0]) {
          dp[i][j][1] = min(dp[i][j][1], a[i]);
        } 
        dp[i][j][1] = min(dp[i][j][1], max(dp[i - 1][j][1], a[i]));
        //cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << '\n';
      }
    }
    //cout << dp[2 * n][n][0] << '\n';
    if (dp[2 * n][n][0] < 1e9 || dp[2 * n][n][1] < 1e9) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }  
}