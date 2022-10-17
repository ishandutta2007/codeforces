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
    if (n == 2) {
      cout << -1 << '\n';
      continue;
    }
    int l = 1, r = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (l <= n * n) {
          cout << l << ' ';
          l += 2;
        }
        else {
          cout << r << ' ';
          r += 2;
        }
      }
      cout << '\n';
    }
  }
}