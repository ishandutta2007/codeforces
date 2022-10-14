#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;
  ll k;
  cin >> k;
  vector<vector<ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (n == 1 && m == 1) {
    cout << (a[0][0] == k ? 1 : 0) << '\n';
    return 0;
  }
  int moves = (n + m - 2) / 2;
  map<tuple<int, int, ll>, ll> cnt;
  for (int i = 0; i < (1 << moves); i++) {
    int x = 0, y = 0;
    ll xr = a[0][0];
    for (int j = 0; j < moves; j++) {
      if (i & (1 << j)) {
        x++;
        if (x >= n) break;
        xr ^= a[x][y];
      } else {
        y++;
        if (y >= m) break;
        xr ^= a[x][y];
      }
    }
    if (x < 0 || x >= n || y < 0 || y >= m) {
      continue;
    }
    cnt[{x, y, xr}]++;
  }
  ll ans = 0;
  int need = n + m - 2 - moves;
  for (int i = 0; i < (1 << need); i++) {
    int x = n - 1, y = m - 1;
    ll xr = 0;
    for (int j = 0; j < need; j++) {
      xr ^= a[x][y];
      if (i & (1 << j)) {
        x--;
        if (x < 0) break;
      } else {
        y--;
        if (y < 0) break;
      }
    }
    if (x < 0 || x >= n || y < 0 || y >= m) {
      continue;
    }
    ans += cnt[{x, y, xr ^ k}];
  }
  cout << ans << '\n';
}