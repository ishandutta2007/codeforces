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
    int ans = 0;
    for (int digit = 1; digit < 10; digit++) {
      int cur = digit;
      while (cur <= n) {
        ans++;
        cur = cur * 10 + digit;
      }
    }
    cout << ans << '\n';
  }
}