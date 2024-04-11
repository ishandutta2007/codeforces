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
 
const int MX = 1010;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int q, d;
    cin >> q >> d;
    vector<int> dp(MX);
    dp[0] = 1;
    vector<bool> ok(MX);
    for (int i = 1; i < MX; i++) {
      int cur = i;
      while (cur > 0) {
        if (cur % 10 == d) {
          ok[i] = true;
          break;
        }
        cur /= 10;
      }
    }
    for (int i = 1; i < MX; i++) {
      for (int j = 1; j <= i; j++) {
        if (ok[j] && dp[i - j]) {
          dp[i] = true;
          break;
        }
      }
    }
    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      if (x >= MX || dp[x]) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}