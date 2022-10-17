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
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<int> dp(n + 1);
    dp[1] = -1e18;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] == b[i]) {
        dp[i] = 2;
      }
      else {
        dp[i] = 2 + max(abs(a[i] - b[i]), (c[i - 1] - max(a[i], b[i])) + (min(a[i], b[i]) - 1) + dp[i - 1]); 
      }
      ans = max(ans, c[i] - 1 + dp[i]);
    }
    cout << ans << '\n';
  }    
}