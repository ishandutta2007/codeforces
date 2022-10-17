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
    int csum, ans = 0;
    cin >> csum;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      int vl = (x * 100ll + k - 1) / k;
      if (vl > csum) {
        ans += vl - csum;
        csum = vl;
      }
      csum += x;
    }
    cout << ans << '\n';
  }
}