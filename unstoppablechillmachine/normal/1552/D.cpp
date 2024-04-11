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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = false;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int mask2 = mask;; mask2 = (mask2 - 1) & mask) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
          if ((mask >> i) & 1) {
            if ((mask2 >> i) & 1) {
              sum += a[i];
            } else {
              sum -= a[i];
            }
          }
        }
        if (sum == 0) {
          ok = true;
        }
        if (mask2 == 0) {
          break;
        }  
      }
      
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}