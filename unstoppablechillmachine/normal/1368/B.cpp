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

int dp[11][810], from[11][810];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  dp[0][0] = 1;
  for (int i = 0; i < 10; i++) {
    for (int was = i; was <= 800; was++) {
      int lim;
      if (dp[i][was] >= k) {
        lim = min(was + 1, 800ll);
      }
      else {
        lim = 800;
      }
      for (int to = was + 1; to <= lim; to++) {
        if (dp[i][was] * (to - was) > dp[i + 1][to]) {
          dp[i + 1][to] = dp[i][was] * (to - was);
          from[i + 1][to] = was;
        }
      }
    }
  }
  int now = -1;
  for (int i = 1; i <= 800; i++) {
    if (dp[10][i] >= k) {
      now = i;
      break;
    }
  }
  assert(now != -1);
  string s = "codeforces";
  string ans;
  for (int i = 10; i >= 1; i--) {
    int nnow = from[i][now];
    for (int j = 0; j < now - nnow; j++) {
      ans.pb(s[i - 1]);
    }
    now = nnow;
  }
  reverse(all(ans));
  cout << ans << '\n';
}