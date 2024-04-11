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
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      sum1 += a;
      sum2 += (a + x - 1) / x; 
    }
    cout << (sum1 + x - 1) / x << ' ' << sum2 << '\n';
  }
}