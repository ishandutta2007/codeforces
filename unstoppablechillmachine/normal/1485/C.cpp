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
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int k = 1; k <= x; k++) {
      if (k * (k + 1) > x) {
        break;
      }
      ans += max(0ll, min(x / k, y + 1) - (k + 1));
    }
    cout << ans << '\n';
  }
}