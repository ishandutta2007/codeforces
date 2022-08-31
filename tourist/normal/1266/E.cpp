/**
 *    author:  tourist
 *    created: 17.12.2019 18:29:45       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  vector<int> b(n);
  map<pair<int, int>, int> mp;
  auto Remove = [&](int s, int t, int u) {
    ans += min(a[u], b[u]);
    --b[u];
    ans -= min(a[u], b[u]);
  };
  auto Add = [&](int s, int t, int u) {
    ans += min(a[u], b[u]);
    ++b[u];
    ans -= min(a[u], b[u]);
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int s, t, u;
    cin >> s >> t >> u;
    --s; --u;
    auto p = make_pair(s, t);
    auto it = mp.find(p);
    if (it != mp.end()) {
      int uu = it->second;
      mp.erase(it);
      Remove(s, t, uu);
    }
    if (u != -1) {
      mp[p] = u;
      Add(s, t, u);
    }
    cout << ans << '\n';
  }
  return 0;
}