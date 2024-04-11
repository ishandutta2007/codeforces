#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  vector<int> x(m);
  vector<int> y(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
  }
  x.push_back(sx);
  y.push_back(sy);
  x.push_back(fx);
  y.push_back(fy);
  m += 2;
  set<pair<int, int>> xs;
  set<pair<int, int>> ys;
  for (int i = 0; i + 1 < m; i++) {
    xs.insert(make_pair(x[i], i));
    ys.insert(make_pair(y[i], i));
  }         
  const int inf = (int) 2.1e9;
  vector<int> dist(m, inf);
  dist[m - 2] = 0;
  set<pair<int, int>> que;
  que.insert(make_pair(0, m - 2));
  function<void(int, int)> Update = [&](int i, int j) {
    int w = min(abs(x[i] - x[j]), abs(y[i] - y[j]));
    if (dist[j] > dist[i] + w) {
      if (dist[j] != inf) {
        que.erase(que.find(make_pair(dist[j], j)));
      }
      dist[j] = dist[i] + w;
      que.insert(make_pair(dist[j], j));
    }
  };
  while (!que.empty()) {  
    int i = que.begin()->second;
    que.erase(que.begin());
    xs.erase(xs.find(make_pair(x[i], i)));
    ys.erase(ys.find(make_pair(y[i], i)));
    {
      auto it = xs.lower_bound(make_pair(x[i], -1));
      if (it != xs.end()) {
        Update(i, it->second);
      }
    }
    {
      auto it = xs.lower_bound(make_pair(x[i], -1));
      if (it != xs.begin()) {
        it = prev(it);
        Update(i, it->second);
      }
    }
    {
      auto it = ys.lower_bound(make_pair(y[i], -1));
      if (it != ys.end()) {
        Update(i, it->second);
      }
    }
    {
      auto it = ys.lower_bound(make_pair(y[i], -1));
      if (it != ys.begin()) {
        it = prev(it);
        Update(i, it->second);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i + 1 < m; i++) {
    ans = min(ans, dist[i] + abs(x[i] - fx) + abs(y[i] - fy));
  }
  cout << ans << '\n';            
  return 0;
}