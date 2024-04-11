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
    vector<char> c(n + 1);
    vector<vector<int>> r(n + 2, vector<int>(2, 0)), l(n + 2, vector<int>(2, 0));
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (c[i + 1] == 'R') {
        r[i][0] = 1 + r[i + 1][1];
      }
      else {
        r[i][1] = 1 + r[i + 1][0];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (c[i] == 'L') {
        l[i][0] = 1 + l[i - 1][1];
      }
      else {
        l[i][1] = 1 + l[i - 1][0];
      }
    }
    for (int i = 0; i <= n; i++) {
      cout << 1 + l[i][0] + r[i][0] << ' ';
    }
    cout << '\n';
  }
}