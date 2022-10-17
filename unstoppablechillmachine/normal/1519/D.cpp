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
 
const int N = 5010;
int a[N], b[N], dp[N][N], pref[N], suf[N], n;

int get_sum(int delta, int l, int r) {
  return dp[delta][r] - dp[delta][l - 1];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    pref[i] = pref[i - 1] + a[i] * b[i];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i] * b[i];
  }
  for (int delta = -n; delta <= 0; delta++) {
    int kek = abs(delta);
    for (int i = 1; i <= n; i++) {
      dp[kek][i] = dp[kek][i - 1];
      if (i + delta >= 1 && i + delta <= n) {
        dp[kek][i] += a[n - i + 1] * b[i + delta];
      }
    }
  }
  int ans = pref[n];
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int rev_l = n - r + 1, rev_r = n - l + 1;
      int sum = pref[l - 1] + suf[r + 1];
      int delta = l - rev_l;
      if (delta <= 0) {
        sum += get_sum(-delta, rev_l, rev_r);
        ans = max(ans, sum);  
      }
    }
  }
  for (int delta = 1; delta <= n; delta++) {
    int kek = abs(delta);
    for (int i = 1; i <= n; i++) {
      dp[kek][i] = dp[kek][i - 1];
      if (i + delta >= 1 && i + delta <= n) {
        dp[kek][i] += a[n - i + 1] * b[i + delta];
      }
    } 
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int rev_l = n - r + 1, rev_r = n - l + 1;
      int sum = pref[l - 1] + suf[r + 1];
      int delta = l - rev_l;
      if (delta >= 0) {
        sum += get_sum(delta, rev_l, rev_r);
        ans = max(ans, sum);  
      }
    }
  }
  cout << ans << '\n';
}