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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (auto &x : a) {
      cin >> x.F;
      x.S = 1;
    }
    int ptr = 0;
    while (ptr < SZ(a)) {
      if (a[ptr].F % x != 0) {
        break;
      }
      a.pb({a[ptr].F / x, x * a[ptr].S});
      ptr++;
    }
    int ans = 0;
    for (auto &x : a) {
      ans += x.F * x.S;
    }
    cout << ans << '\n';
  }
}