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
    vector<vector<int>> b(n, vector<int>(m));
    vector<pair<int, pair<int, int>>> al;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        al.pb({b[i][j], {i, j}});
      }
    }
    sort(all(al));
    vector<vector<int>> go(n, vector<int>(m));
    vector<vector<bool>> used(n, vector<bool>(m));
    for (int i = 0; i < m; i++) {
      go[al[i].S.F][i] = al[i].F;
      used[al[i].S.F][al[i].S.S] = true;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!go[i][j]) {
          for (int j2 = 0; j2 < m; j2++) {
            if (!used[i][j2]) {
              go[i][j] = b[i][j2];
              used[i][j2] = true;
              break;
            }
          }
        }
        cout << go[i][j] << ' ';
      }
      cout << '\n';
    }

  }
}