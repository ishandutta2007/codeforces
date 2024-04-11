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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (i == n && j == m) {
          continue;
        }
        if (i == n && c == 'D') {
          ans++;
        }
        if (j == m && c == 'R') {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}