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

const int N = 2e5 + 10;
vector<int> g[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[v].pb(u);
    }
    vector<int> kek(n + 1), rez;
    for (int i = 1; i <= n; i++) {
      for (int j : g[i]) {
        kek[i] = max(kek[i], kek[j] + 1);
      }
      if (kek[i] == 2) {
        kek[i] = -1;
        rez.pb(i);
      }
    }
    cout << SZ(rez) << '\n';
    for (auto v : rez) {
      cout << v << ' ';
    }
    cout << '\n';
  }
}