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
    vector<int> color(2, -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == '.') {
          continue;
        }
        int id = (i % 2) ^ (j % 2);
        int cl = (c == 'W' ? 1 : 0);
        if (color[id] == (cl ^ 1)) {
          ok = false;
        } else {
          color[id] = cl;
        }
      }
    }
    if ((color[0] == 0 && color[1] == 0) || (color[0] == 1 && color[1] == 1)) {
      ok = false;
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (color[0] != 1 && color[1] != 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int id = (i % 2) ^ (j % 2);
          if (id == 0) {
            cout << 'R';
          } else {
            cout << 'W';
          }
        }
        cout << '\n';
      }
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int id = (i % 2) ^ (j % 2);
          if (id == 1) {
            cout << 'R';
          } else {
            cout << 'W';
          } 
        }
        cout << '\n';
      }
    }
  }
}