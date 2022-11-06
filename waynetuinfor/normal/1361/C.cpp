#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> deg(1 << 20);
  vector<int> uf(1 << 20);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  for (int bit = 20; bit >= 0; --bit) {
    fill(deg.begin(), deg.begin() + (1 << bit), 0);
    iota(uf.begin(), uf.begin() + (1 << bit), 0);

    function<int(int)> Find = [&](int x) {
      if (x == uf[x]) return x;
      return uf[x] = Find(uf[x]);
    };

    auto Merge = [&](int x, int y) {
      x = Find(x);
      y = Find(y);
      uf[x] = y;
    };

    for (int i = 0; i < n; ++i) {
      int x = a[i] & ((1 << bit) - 1);
      int y = b[i] & ((1 << bit) - 1);
      Merge(x, y);
      deg[x]++;
      deg[y]++;
    }
    bool ok = true;
    for (int i = 0; i < (1 << bit); ++i) {
      ok &= deg[i] % 2 == 0;
    }
    int z = Find(a[0] & ((1 << bit) - 1));
    for (int i = 0; i < n; ++i) {
      int x = a[i] & ((1 << bit) - 1);
      int y = b[i] & ((1 << bit) - 1);
      ok &= Find(x) == z && Find(y) == z;
    }
    if (ok) {
      cout << bit << "\n";
      vector<set<pair<int, int>>> g(1 << bit);
      for (int i = 0; i < n; ++i) {
        int x = a[i] & ((1 << bit) - 1);
        int y = b[i] & ((1 << bit) - 1);
        g[x].insert(make_pair(y, i));
        g[y].insert(make_pair(x, i));
      }

      vector<bool> used(n);
      vector<int> ed;

      auto Dfs = [&](auto dfs, int x) -> void {
        while (!g[x].empty()) {
          auto e = *g[x].begin();
          int y = e.first;
          int id = e.second;
          g[x].erase(e);
          g[y].erase(make_pair(x, id));
          dfs(dfs, y);
          ed.push_back(id);
        }
      };

      Dfs(Dfs, z);
      assert(ed.size() == n);
      for (int i = 0; i < n; ++i) {
        int j = ed[i];
        int x = a[j] & ((1 << bit) - 1);
        int y = b[j] & ((1 << bit) - 1);
        bool s = false;
        if (y == z) {
          swap(x, y);
          s = true;
        }
        if (s) cout << 2 * j + 2 << " " << 2 * j + 1 << " ";
        else cout << 2 * j + 1 << " " << 2 * j + 2 << " ";
        z = y;
      }
      cout << "\n";
      return 0;
    }
  }
  assert(false);
}