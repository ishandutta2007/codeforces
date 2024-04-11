/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 16:10:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    --u[i]; --v[i];
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  vector<int> deg(n);
  vector<int> rem(n);
  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
    rem[i] = deg[i] / 2;
  }         
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    st.emplace(-rem[i], i); 
  }
  set<pair<int, int>> edges;
  while (!st.empty()) {
    auto it = st.begin();
    int i = it->second;
    st.erase(it);
    sort(g[i].begin(), g[i].end(), [&](int x, int y) {
      return rem[x] > rem[y];
    });
    int ptr = 0;      
    while (rem[i]--) {
      int to = g[i][ptr];
      if (rem[to] > 0) {
        edges.emplace(i, to);
        if (st.find({-rem[to], to}) != st.end()) {
          st.erase(st.find({-rem[to], to}));
        }
        rem[to] -= 1;
        if (rem[to] > 0) {
          st.emplace(-rem[to], to);
        }
      }
      ptr += 1;
    }
  }
  cout << m - (int) edges.size() << '\n';
  for (int i = 0; i < m; i++) {
    if (!edges.count({u[i], v[i]}) && !edges.count({v[i], u[i]})) {
      cout << u[i] + 1 << " " << v[i] + 1 << '\n';
    }
  }            
  return 0;
}