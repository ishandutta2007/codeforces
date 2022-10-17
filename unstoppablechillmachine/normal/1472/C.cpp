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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      int to = min(i + a[i], n + 1);
      dp[i] = dp[to] + a[i];
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}