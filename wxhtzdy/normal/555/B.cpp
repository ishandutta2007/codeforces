#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<long long> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  vector<long long> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  map<long long, vector<pair<int, int>>> mp;
  vector<long long> L(n), R(n);
  for (int i = 0; i + 1 < n; i++) {
    L[i] = l[i + 1] - r[i];
    R[i] = r[i + 1] - l[i];
    mp[L[i]].emplace_back(i, -1);
    mp[R[i]].emplace_back(i, 1);
  }                              
  for (int i = 0; i < m; i++) {
    mp[a[i]].emplace_back(i, 0);
  }        
  set<pair<long long, int>> act;
  vector<int> ans(n - 1, -1);
  for (auto p : mp) {
    auto v = p.second;
    for (auto q : v) {
      if (q.second == -1) {
        act.insert({R[q.first], q.first});
      }
    }
    for (auto q : v) {
      if (q.second == 0) {
        if (!act.empty()) {
          auto it = act.begin();
          ans[(*it).second] = q.first;
          act.erase(it);
        }
      }
    }
    for (auto q : v) {
      if (q.second == 1) {
        if (ans[q.first] == -1) {
          cout << "No" << '\n';
          return 0;
        }
      }
    }
  }
  if (*min_element(ans.begin(), ans.end()) == -1) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  for (int i = 0; i + 1 < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}