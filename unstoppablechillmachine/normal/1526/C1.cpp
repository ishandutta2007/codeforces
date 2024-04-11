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

const int N = 2010;
int dp[N][N], a[N];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    for (int j = 1; j <= n; j++) {
      if (dp[i - 1][j - 1] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
      }
    }
  }
  int ans = n;
  while (dp[n][ans] < 0) {
    ans--;
  }
  cout << ans << '\n';
}