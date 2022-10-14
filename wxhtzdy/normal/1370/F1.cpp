#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto Ask = [&](vector<int> ids) {
      cout << "? " << ids.size() << " ";
      for (int i = 0; i < ids.size(); i++) {
        cout << ids[i] + 1 << " ";
      }
      cout << endl;       
      int id, d;
      cin >> id >> d;
      return make_pair(id - 1, d);
    };
    vector<int> all(n);
    iota(all.begin(), all.end(), 0);
    auto who = Ask(all);
    int root = who.first;
    int dist = who.second; 
    vector<int> dep(n);
    vector<vector<int>> ver(n);
    vector<int> dfn(n);
    vector<int> dfo(n);
    int T = 0;
    function<void(int, int)> Dfs = [&](int v, int pv) {
      dfn[v] = ++T;
      ver[dep[v]].push_back(v);
      for (int u : g[v]) {
        if (u == pv) {
          continue;
        }
        dep[u] = dep[v] + 1;
        Dfs(u, v);
      }
      dfo[v] = T;
    };
    Dfs(root, root);
    int low = 0, high = n - 1, uid;
    while (low <= high) {
      int mid = (low + high + 1) >> 1;
      if (!ver[mid].empty()) {
        auto it = Ask(ver[mid]);
        if (it.second > dist) {
          high = mid - 1;     
        } else {
          uid = it.first;
          low = mid + 1;
        }
      } else {
        high = mid - 1;
      }
    }           
    int vdep = dist - dep[uid];
    int vf;
    auto is = [&](int p, int v) {
      return dfn[p] <= dfn[v] && dfo[v] <= dfo[p];
    };
    for (int i = 0; i < g[root].size(); i++) {
      if (is(g[root][i], uid)) {
        vf = g[root][i];
      }
    }
    vector<int> cands;
    for (int i = 0; i < ver[vdep].size(); i++) {
      if (!is(vf, ver[vdep][i])) {
        cands.push_back(ver[vdep][i]);
      }
    }
    int vid = Ask(cands).first + 1;
    cout << "! " << uid + 1 << " " << vid << endl;
    string foo;
    cin >> foo;
  }                                                                    
  return 0;
}