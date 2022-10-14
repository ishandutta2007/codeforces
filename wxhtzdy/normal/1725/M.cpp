/**
 *    author:  wxhtzdy
 *    created: 16.09.2022 19:19:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  vector<vector<pair<int, int>>> r(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[x].emplace_back(y, z);
    r[y].emplace_back(x, z);
  }
  const long long inf = 1e18;
  vector<long long> dist(n, inf);
  dist[0] = 0;
  set<pair<long long, int>> st;
  st.emplace(0, 0);
  while (!st.empty()) {
    auto it = st.begin();
    int i = it->second;
    st.erase(it);
    for (auto& p : g[i]) {
      int j = p.first;
      int w = p.second;
      if (dist[j] > dist[i] + w) {
        if (dist[j] != inf) {
          st.erase(st.find({dist[j], j})); 
        }
        dist[j] = dist[i] + w;
        st.emplace(dist[j], j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dist[i] != inf) {
      st.emplace(dist[i], i);
    }
  }
  while (!st.empty()) {
    auto it = st.begin();
    int i = it->second;
    st.erase(it);
    for (auto& p : r[i]) {
      int j = p.first;
      int w = p.second;
      if (dist[j] > dist[i] + w) {
        if (dist[j] != inf) {
          st.erase(st.find({dist[j], j})); 
        }
        dist[j] = dist[i] + w;
        st.emplace(dist[j], j);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << (dist[i] == inf ? -1 : dist[i]) << " ";
  }                              
  return 0;
}