/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 21:11:35
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> u(m), v(m);
    vector<int> ids;
    dsu d(n);
    for (int i = 0; i < m; i++) {
      cin >> u[i] >> v[i];
      --u[i]; --v[i];
      if (d.unite(u[i], v[i])) {
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
      } else { 
        ids.push_back(i);
      }
    }
    string ans = string(m, '0');
    for (int i : ids) {
      ans[i] = '1';
    }              
    if (ids.size() == 3) {            
      vector<pair<int, int>> edges;
      for (int i : ids) {
        edges.emplace_back(min(u[i], v[i]), max(u[i], v[i]));
      }
      sort(edges.begin(), edges.end());
      int a = edges[0].first;
      int b = edges[0].second;
      int c = edges[1].second;
      vector<pair<int, int>> cyc;
      cyc.emplace_back(a, b);
      cyc.emplace_back(a, c);
      cyc.emplace_back(b, c);
      if (edges == cyc) {
        vector<int> new_u(m);
        vector<int> new_v(m);
        new_u[0] = u[ids[0]];
        new_v[0] = v[ids[0]];
        int ptr = 1;
        vector<int> id(1, ids[0]);
        for (int i = 0; i < m; i++) {
          if (i == ids[0]) {
            continue;
          }  
          id.push_back(i);
          new_u[ptr] = u[i];
          new_v[ptr] = v[i];
          ptr += 1;
        }
        swap(u, new_u);
        swap(v, new_v);
        for (int i = 0; i < n; i++) {
          d.p[i] = i;
        }     
        ans = string(m, '0');
        for (int i = 0; i < m; i++) {
          if (!d.unite(u[i], v[i])) {
            ans[id[i]] = '1';
          }
        }
      }
    }
    cout << ans << '\n';
  }                                                                      
  return 0;
}