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
    int mx = 0;
    for (int wins = 1; wins <= n - 1; wins++) {
      if (n * wins <= n * (n - 1) / 2) {
        mx = wins;
      }
    }
    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      int cur = i + 1;
      if (cur == n + 1) {
        cur = 1;
      }
      for (int j = 0; j < mx; j++) {
        result[i][cur] = 1;
        result[cur][i] = -1;
        cur++;
        if (cur == n + 1) {
          cur = 1;
        }
      }
    }
    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          continue;
        }
        if (result[i][j] == 1) {
          score[i] += 3;
        }
        else if (result[i][j] == 0) {
          score[i]++;
        }
      }
      assert(score[i] == score[1]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        cout << result[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}