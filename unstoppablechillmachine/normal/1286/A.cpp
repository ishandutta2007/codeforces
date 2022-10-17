#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 110;
int dp[N][N][N][2], a[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
  cin >> n;
  int cnt1 = (n + 1) / 2, cnt2 = n / 2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] & 1) {
      cnt1--;
    }
    else if (a[i]) {
      cnt2--;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int was1 = 0; was1 <= cnt1; was1++) {
      for (int was2 = 0; was2 <= cnt2; was2++) {
        dp[i][was1][was2][0] = dp[i][was1][was2][1] = 1e9;
      }
    }
  }
  if (a[1]) {
    dp[1][0][0][a[1] % 2] = 0;
  }
  else {
    if (cnt1) {
      dp[1][1][0][1] = 0;
    }
    if (cnt2) {
      dp[1][0][1][0] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int was1 = 0; was1 <= cnt1; was1++) {
      for (int was2 = 0; was2 <= cnt2; was2++) {
        for (int lst = 0; lst < 2; lst++) {
          if (a[i + 1]) {
            dp[i + 1][was1][was2][a[i + 1] % 2] = min(dp[i + 1][was1][was2][a[i + 1] % 2], dp[i][was1][was2][lst] + (lst != a[i + 1] % 2));
          }
          else {
            if (was1 < cnt1) {
              dp[i + 1][was1 + 1][was2][1] = min(dp[i + 1][was1 + 1][was2][1], dp[i][was1][was2][lst] + (lst ^ 1));
            }
            if (was2 < cnt2) {
              dp[i + 1][was1][was2 + 1][0] = min(dp[i + 1][was1][was2 + 1][0], dp[i][was1][was2][lst] + lst);
            }
          }
        }
      }
    }
  }
  if (a[n]) {
    cout << dp[n][cnt1][cnt2][a[n] % 2] << '\n';
  }
  else {
    cout << min(dp[n][cnt1][cnt2][0], dp[n][cnt1][cnt2][1]) << '\n';
  }
}