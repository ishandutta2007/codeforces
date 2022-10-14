/**
 *    author:  wxhtzdy
 *    created: 24.08.2022 17:23:55
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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    dsu d(n);
    vector<int> col(n);
    vector<vector<int>> ch(n);
    for (int i = 0; i < n; i++) {
      ch[i].push_back(i);
    }
    auto Unite = [&](int x, int y, int z) {
      z ^= (col[x] ^ col[y]);      
      x = d.get(x);
      y = d.get(y);
      if (ch[x].size() > ch[y].size()) {
        swap(x, y);
      }
      for (auto& p : ch[x]) {
        ch[y].push_back(p);
        col[p] ^= z;  
      }
      ch[x].clear();
      d.unite(x, y);
    };
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (d.get(i) == d.get(j)) {
          continue;
        }
        if (a[i][j] == a[j][i]) {
          continue;
        }
        if (a[i][j] < a[j][i]) {
          Unite(i, j, 0);
        } else {
          Unite(i, j, 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (col[i] == 1) {
        for (int j = 0; j < n; j++) {
          swap(a[i][j], a[j][i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << " \n"[j == n - 1];
      }
    }
  }                                                                     
  return 0;
}