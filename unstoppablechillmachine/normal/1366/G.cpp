#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 10010;
int dp[N][N], calc[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int n = SZ(s), m = SZ(t);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] != '.') {
      int balance = 1;
      calc[i] = -1;
      for (int j = i + 1; j <= n; j++) {
        if (s[j - 1] == '.') {
          balance--;
          if (balance == 0) {
            calc[i] = j;
            break;
          }
        }
        else {
          balance++;
        }
      }
    }
  } 
  //cout << calc[4] << '\n';
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = -n;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j < m && s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      if (j > 0 && s[i] == '.') {
        dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + 1);
      }
      if (s[i] != '.' && calc[i + 1] != -1) {
        dp[calc[i + 1]][j] = max(dp[calc[i + 1]][j], dp[i][j] + calc[i + 1] - i);
      }
    }
  }
  //cout << dp[6][2] << '\n';
  cout << n - dp[n][m] << '\n';
}