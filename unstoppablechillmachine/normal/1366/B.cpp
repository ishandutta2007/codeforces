#pragma GCC optimize("O3")
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
    int n, x, m;
    cin >> n >> x >> m;
    pair<int, int> cur = {x, x};
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      if (max(l, cur.F) <= min(r, cur.S)) {
        cur.F = min(l, cur.F);
        cur.S = max(cur.S, r);
      }
    }
    cout << cur.S - cur.F + 1 << '\n';
  }  
}