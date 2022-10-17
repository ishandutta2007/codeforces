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
    int n, u, v;
    cin >> n >> u >> v;
    int a;
    cin >> a;
    bool col = true, can_0 = false;
    int prv = a;
    for (int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      if (x != a) {
        col = false;
      }
      if (abs(x - prv) > 1) {
        can_0 = true;
      }
      prv = x;
    }
    if (can_0) {
      cout << 0 << '\n';
      continue;
    }
    if (col) {
      cout << min(2 * v, u + v) << '\n'; 
    }
    else {
      cout << min(u, v) << '\n';
    }
  }
}