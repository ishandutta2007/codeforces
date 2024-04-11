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
  int n, m;
  cin >> n >> m;
  vector<dsu> d(30, dsu(n));
  vector<bool> have(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    for (int j = 0; j < 30; j++) {
      if (w >> j & 1) {
        d[j].unite(u, v);
      }
    }
    if ((w & 1) == 0) {
      have[u] = true;
      have[v] = true;
    }
  }
  vector<vector<bool>> good(30, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    if (!have[i]) {
      continue;
    }
    for (int j = 1; j < 30; j++) {
      good[j][d[j].get(i)] = true;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    bool zer = false;
    for (int i = 0; i < 30; i++) {
      if (d[i].get(u) == d[i].get(v)) {
        zer = true;
      }
    }
    if (zer) {
      cout << 0 << '\n';
      continue;
    }                   
    int ans = 2;
    for (int i = 1; i < 30; i++) {
      if (good[i][d[i].get(u)]) {
        ans = 1;
      }
    }
    cout << ans << '\n';
  }                                                                  
  return 0;
}