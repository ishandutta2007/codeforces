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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> guy(k + 1), girl(k + 1), cnt_b(a + 1), cnt_g(b + 1);
    for (int i = 1; i <= k; i++) {
      cin >> guy[i];
      cnt_b[guy[i]]++;
    }
    for (int i = 1; i <= k; i++) {
      cin >> girl[i];
      cnt_g[girl[i]]++;
    }
    int ans = k * (k - 1) / 2;
    for (int i = 1; i <= a; i++) {
      if (cnt_b[i]) {
        ans -= cnt_b[i] * (cnt_b[i] - 1) / 2;
      }
    }
    for (int i = 1; i <= b; i++) {
      if (cnt_g[i]) {
        ans -= cnt_g[i] * (cnt_g[i] - 1) / 2;
      }
    }
    cout << ans << '\n';
  }
}