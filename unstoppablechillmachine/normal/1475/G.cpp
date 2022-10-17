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
 
const int N = 2e5 + 10;
int cnt[N], dp[N];;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2e5; i++) {
      cnt[i] = 0;
      dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 2e5; i++) {
      dp[i] = max(dp[i], cnt[i]);
      ans = max(ans, dp[i]);
      for (int j = 2 * i; j <= 2e5; j += i) {
        dp[j] = max(dp[j], dp[i] + cnt[j]);
      }
    }
    cout << n - ans << '\n';
  }
}