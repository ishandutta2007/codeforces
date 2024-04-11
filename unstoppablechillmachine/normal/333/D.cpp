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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> have(n + 1), used(m + 1, vector<int>(m + 1));
  int l = 0, r = 1e9 + 10, timer = 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
      have[i] = {};
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] >= mid) {
          have[i].pb(j);
        }
      }
    }
    timer++;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      for (int id1 = 0; id1 < SZ(have[i]); id1++) {
        for (int id2 = id1 + 1; id2 < SZ(have[i]); id2++) {
          if (used[have[i][id1]][have[i][id2]] == timer) {
            ok = true;
            break;
          }
          used[have[i][id1]][have[i][id2]] = timer;
        }
        if (ok) {
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    if (ok) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << l << '\n';
}