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
    int lst = -1, mx = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x == lst) {
        cnt++;
      }
      else {
        lst = x;
        cnt = 1;
      }
      mx = max(mx, cnt);
    }
    cout << mx << '\n';
  }
}