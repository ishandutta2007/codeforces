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
 
signed main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<bool>> current(2, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      current[0][i] = s[i] - '0';
    }
    for (int i = 0; i < m; i++) {
      int upds = 0;
      for (int j = 0; j < n; j++) {
        if (current[0][j]) {
          current[1][j] = 1;
          continue;
        }
        int neig = 0;
        if (j > 0 && current[0][j - 1]) {
          neig++;
        }
        if (j + 1 < n && current[0][j + 1]) {
          neig++;
        }
        if (neig == 1) {
          upds++;
          current[1][j] = 1;
        } else {
          current[1][j] = 0;
        }
      }
      current[0].swap(current[1]);
      if (!upds) {
        break;
      }
    }
    for (auto it : current[0]) {
      cout << it;
    }
    cout << '\n';
  }
}