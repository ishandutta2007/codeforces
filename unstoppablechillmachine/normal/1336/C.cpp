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

const int N = 3010;
const int MOD = 998244353;
int dp[N][N], dp2[N][N][2];

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int n = SZ(s), m = SZ(t);
  for (int i = 1; i <= m; i++) {
    if (t[i - 1] == s[0]) {
      dp2[i][i][0] = dp2[i][i][1] = 1;  
    }
  }
  for (int len = 1; len < m; len++) {
    for (int l = 1; l + len - 1 <= m; l++) {
      int r = l + len - 1;
      //cout << l << ' ' << r << ' ' << dp2[l][r][0] << ' ' << dp2[l][r][1] << '\n'; 
      for (int lst = 0; lst < 2; lst++) {
        if (r < m && s[len] == t[r]) {
          add(dp2[l][r + 1][1], dp2[l][r][lst]);
        }
        if (l > 1 && s[len] == t[l - 2]) {
          add(dp2[l - 1][r][0], dp2[l][r][lst]);
        }
      }
    }
  }
  reverse(all(s));
  for (int moves = 0; moves <= n; moves++) {
    dp[moves][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int cnt = 0; cnt <= m; cnt++) {
      if (cnt == m) {
        add(dp[i + 1][m], (2 * dp[i][m]) % MOD);
        continue;
      }
      add(dp[i + 1][cnt], dp[i][cnt]);
      if (s[i] == t[cnt]) {
        add(dp[i + 1][cnt + 1], dp[i][cnt]);
      }
    }
  }
  int ans = dp[n][m];
  //cout << ans << '\n';
  //cout << dp2[1][m][1] << '\n';
  for (int ad = 1; ad <= m; ad++) {
    int cur = dp[n - ad][m - ad];

    add(ans, mult(cur, dp2[m - ad + 1][m][1]));
  }
  cout << ans << '\n';
}