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

const int N = 1e5 + 10;
int t[N], a[N], b[N], dp[N], pref[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int r, n;
  cin >> r >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> a[i] >> b[i];
  }
  a[0] = b[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = -1e9;
    for (int j = i - 1; j >= 0; j--) {
      if (t[i] - t[j] > 2 * r) {
        dp[i] = max(dp[i], pref[j] + 1);
        break;
      }
      if (t[j] + abs(a[i] - a[j]) + abs(b[i] - b[j]) <= t[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    pref[i] = max(pref[i - 1], dp[i]);
  }
  cout << pref[n] << '\n';
}