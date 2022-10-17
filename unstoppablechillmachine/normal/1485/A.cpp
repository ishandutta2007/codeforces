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
    int a, b;
    cin >> a >> b;
    int ans = 1e9;
    for (int cnt = 0; cnt <= 40; cnt++) {
      if (b + cnt == 1) {
        continue;
      }
      int cur = a, sum = cnt;
      while (cur > 0) {
        cur /= (b + cnt);
        sum++;
      }
      ans = min(ans, sum);
    }
    cout << ans << '\n';
  }
}