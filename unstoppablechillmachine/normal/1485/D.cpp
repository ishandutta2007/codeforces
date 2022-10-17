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
 
const int MX = 16;
const int L = 1e6;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int lcm = 1;
  for (int i = 2; i <= MX; i++) {
    lcm = (lcm * i) / __gcd(i, lcm);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % 2 == j % 2) {
        cout << lcm << ' ';
      }
      else {
        for (int k = 1; k * k * k * k <= L; k++) {
          int vl1 = lcm - k * k * k * k, vl2 = lcm + k * k * k * k;
          if (vl1 >= 1 && vl1 % a[i][j] == 0) {
            cout << vl1 << ' ';
            break;
          }
          if (vl2 <= L && vl2 % a[i][j] == 0) {
            cout << vl2 << ' ';
            break;
          }
        }
      }
    }
    cout << '\n';
  }
}