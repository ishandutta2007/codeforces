#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
signed main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> kek(m + 1, vector<int>(5));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      kek[j][c - 'A']++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int cost;
    cin >> cost;
    int mx = 0;
    for (int j = 0; j < 5; j++) {
      mx = max(mx, kek[i][j]);
    }
    ans += cost * mx;
  }
  cout << ans << '\n';
}