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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &it : a) {
      cin >> it.F >> it.S;
    }
    bool can = false;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (abs(a[i].F - a[j].F) + abs(a[i].S - a[j].S) > k) {
          ok = false;
        }
      }
      if (ok) {
        can = true;
      }
    }
    if (can) {
      cout << 1 << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
}