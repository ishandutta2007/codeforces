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
    vector<vector<bool>> ans(n, vector<bool>(m, false));
    for (int i = 0; i < m; i += 2) {
      ans[0][i] = true;
    }
    for (int i = 2; i < n; i += 2) {
      ans[i][m - 1] = true;
    }
    for (int i = m - 3; i >= 0; i -= 2) {
      ans[n - 1][i] = true;
    }
    for (int i = n - 3; i >= 2; i -= 2) {
      ans[i][0] = true;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << (ans[i][j] ? 1 : 0);
      }
      cout << '\n';
    }
    cout << '\n';
  }
}