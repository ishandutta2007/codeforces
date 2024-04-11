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
 
const int N = 310;
int a[N][N], ans[N][N];
vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        int cnt = 0;
        for (auto it : delta) {
          int i2 = it.F + i, j2 = it.S + j;
          if (i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m) {
            cnt++;
          }
        }
        if (cnt < a[i][j]) {
          ok = false;
        }
        ans[i][j] = cnt;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << ans[i][j] << ' ';
        }
        cout << '\n';
      }
    }
  } 
}