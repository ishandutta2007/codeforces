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
  vector<int> sz(4);
  for (auto &it : sz) {
    cin >> it;
  }
  vector<vector<int>> a(4);
  for (int i = 0; i < 4; i++) {
    a[i].resize(sz[i]);
    for (auto &it : a[i]) {
      cin >> it;
    }
  }
  auto solve = [](vector<int> cost1, vector<int> cost2) {
    vector<pair<int, int>> order;
    for (int i = 0; i < SZ(cost1); i++) {
      order.pb({cost1[i], i});
    }
    sort(all(order));
    int cnt_bad;
    cin >> cnt_bad;
    vector<set<int>> ban(SZ(cost2));
    for (int i = 0; i < cnt_bad; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      ban[v].insert(u);
    }
    vector<int> rez;
    for (int i = 0; i < SZ(cost2); i++) {
      int best = 1e9;
      for (auto it : order) {
        if (!ban[i].count(it.S)) {
          best = it.F;
          break;
        }
      }
      rez.pb(min((int)1e9, best + cost2[i]));
    }
    return rez;
  };  
  for (int i = 1; i < 4; i++) {
    a[i] = solve(a[i - 1], a[i]);
  }
  int ans = 1e9;
  for (auto it : a[3]) {
    ans = min(ans, it);
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
}