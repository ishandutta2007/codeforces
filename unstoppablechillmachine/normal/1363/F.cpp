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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s1 = s, t1 = t;
    sort(all(s1)); sort(all(t1));
    if (s1 != t1) {
      cout << -1 << '\n';
      continue;
    }
    vector<vector<int>> cnt_s(n + 1, vector<int>(26)), cnt_t(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
      cnt_s[i] = cnt_s[i - 1];
      cnt_s[i][s[i - 1] - 'a']++;
      cnt_t[i] = cnt_t[i - 1];
      cnt_t[i][t[i - 1] - 'a']++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (i < n && t[i] == s[j]) {
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        }
        if (i < n) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }
        if (j < i && cnt_s[j][s[j] - 'a'] < cnt_t[i][s[j] - 'a']) {
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
      }
    }
    cout << dp[n][n] << '\n';
  }  
}