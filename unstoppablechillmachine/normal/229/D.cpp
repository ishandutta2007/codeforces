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
  int n;
  cin >> n;
  vector<int> pref(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1e9)), suf(n + 1, vector<int>(n + 1, -1e9));
  dp[1][1] = 1;
  suf[1][1] = 1;
  for (int r = 2; r <= n; r++) {
    int ptr = r;
    for (int l = r; l >= 1; l--) {
      if (l == 1) {
        dp[l][r] = 1;
        continue;
      }
      if (a[l - 1] > pref[r] - pref[l - 1]) {
        continue;
      }
      ptr = min(ptr, l - 1);
      while (ptr > 1 && pref[l - 1] - pref[ptr - 2] <= pref[r] - pref[l - 1]) {
        ptr--;
      }
      dp[l][r] = suf[l - 1][ptr] + 1;
    }
    suf[r][r] = dp[r][r];
    for (int l = r - 1; l >= 1; l--) {
      suf[r][l] = max(suf[r][l + 1], dp[l][r]);
    }
  }
  cout << n - suf[n][1] << '\n';
}