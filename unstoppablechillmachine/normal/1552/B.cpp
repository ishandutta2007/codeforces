#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
const int m = 5;
const int inf = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> r[i][j];
      }
    }
    int current = 0;
    for (int i = 1; i < n; i++) {
      int good = 0;
      for (int j = 0; j < m; j++) {
        if (r[current][j] < r[i][j]) {
          good++;
        }
      }
      if (good < 3) {
        current = i;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i == current) {
        continue;
      }
      int good = 0;
      for (int j = 0; j < m; j++) {
        if (r[current][j] < r[i][j]) {
          good++;
        }
      }
      if (good < 3) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      cout << current + 1 << '\n';
    }
  }
}