#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    vector<int> par(3 * n + 1, -1);
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      if (par[u] == -1 && par[v] == -1) {
        par[u] = v;
        par[v] = u;
        ans.pb(i + 1);
      }
    }
    if (SZ(ans) >= n) {
      cout << "Matching\n";
      for (int i =0 ; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
    else {
      cout << "IndSet\n";
      int cnt = 0;
      for (int i = 1; i <= 3 * n; i++) {
        if (par[i] == -1 && cnt < n) {
          cout << i << ' ';
          cnt++;
        }
      }
      cout << '\n';
    }
  }
}