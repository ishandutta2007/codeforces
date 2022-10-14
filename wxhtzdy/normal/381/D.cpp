/**
 *    author:  wxhtzdy
 *    created: 07.07.2022 16:37:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> op(m);
  vector<int> t(m);
  vector<int> l(m), r(m); 
  vector<int> x(m);
  vector<int> v(m);
  for (int i = 0; i < m; i++) {
    cin >> op[i];
    if (op[i] == 1) {
      cin >> t[i] >> l[i] >> r[i] >> x[i];
    } else {
      cin >> t[i] >> v[i]; 
    }
  }
  {
    vector<int> xs;
    for (int i = 0; i < m; i++) {
      if (op[i] == 1) {
        xs.push_back(x[i]);
      }
    }
    sort(xs.begin(), xs.end());
    for (int i = 0; i < m; i++) {
      x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
    }
  }
  vector<pair<int, int>> xs;
  for (int i = 0; i < m; i++) {
    if (op[i] == 2) {
      xs.emplace_back(t[i], v[i]);
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  vector<vector<pair<int, int>>> ver(n + 1);
  for (int i = 0; i < m; i++) {
    int id = lower_bound(xs.begin(), xs.end(), make_pair(t[i], v[i])) - xs.begin();
    ver[t[i]].emplace_back(v[i], id);
  }                        
  int sz = (int) xs.size();
  vector<vector<int>> cnt(sz, vector<int>(m));
  vector<int> ans(sz);
  function<void(int, int)> Add = [&](int i, int x) {
    if (cnt[i][x] == 0) {
      ans[i] += 1;
    }
    cnt[i][x] = 1;
  };
  const int MAX = (int) 1e6;
  vector<int> par(MAX + 5);
  int ptr = 1;
  for (int i = 1; i < MAX && ptr < MAX; i++) {
    if (__builtin_popcount(i) == 1) {
      par[ptr] = i;
      ptr += 1;
      par[ptr] = i;
      ptr += 1;
    } else {
      par[ptr] = i;
      ptr += 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (op[i] == 1) {
      while (t[i] > 0) {
        for (auto &p : ver[t[i]]) {
          if (l[i] <= p.first && p.first <= r[i]) {
            Add(p.second, x[i]);
          }
        }
        l[i] = par[l[i]];
        r[i] = par[r[i]];
        t[i] -= 1;
      }
    } else {
      int id = lower_bound(xs.begin(), xs.end(), make_pair(t[i], v[i])) - xs.begin();
      cout << ans[id] << '\n';
    }
  }
  return 0;
}