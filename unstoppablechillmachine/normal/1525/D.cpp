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
 
const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> ones, zeros;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      ones.pb(i);
    }
    else {
      zeros.pb(i);
    }
  }
  vector<vector<int>> dp(SZ(ones) + 1, vector<int>(SZ(zeros) + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= SZ(ones); i++) {
    for (int j = i; j <= SZ(zeros); j++) {
      if (j < SZ(zeros)) {
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
      }
      if (i < SZ(ones) && j < SZ(zeros)) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(ones[i] - zeros[j]));
      }
    }
  }
  cout << dp[SZ(ones)][SZ(zeros)] << '\n';
}