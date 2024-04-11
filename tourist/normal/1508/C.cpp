/**
 *    author:  tourist
 *    created: 16.04.2021 17:47:15       
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
  int n, m;
  cin >> n >> m;
  long long total = (long long) n * (n - 1) / 2;
  if (total - m >= n) {
    vector<vector<int>> g(n);
    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      e[i] = make_tuple(z, x, y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end());
    }
    set<int> alive;
    for (int i = 0; i < n; i++) {
      alive.insert(i);
    }
    dsu d(n);
    while (!alive.empty()) {
      int st = *alive.begin();
      alive.erase(alive.begin());
      vector<int> que(1, st);
      for (int b = 0; b < (int) que.size(); b++) {
        int i = que[b];
        auto it = alive.begin();
        while (it != alive.end()) {
          auto iter = lower_bound(g[i].begin(), g[i].end(), *it);
          if (iter != g[i].end() && *iter == *it) {
            ++it;
            continue;
          }
          que.push_back(*it);
          d.unite(st, que.back());
          it = alive.erase(it);
        }
      }
    }
    sort(e.begin(), e.end());
    long long ans = 0;
    for (auto& p : e) {
      int x = get<1>(p);
      int y = get<2>(p);
      int z = get<0>(p);
      if (d.unite(x, y)) {
        ans += z;
      }
    }
    cout << ans << '\n';
  } else {
    vector<vector<int>> g(n, vector<int>(n, 0));
    int val = 0;
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      g[x][y] = g[y][x] = z;
      val ^= z;
    }
    vector<tuple<int, int, int>> e;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        e.emplace_back(g[i][j], i, j);
      }
    }
    sort(e.begin(), e.end());
    dsu d(n);
    vector<tuple<int, int, int>> taken;
    long long ans = 0;
    bool done = false;
    for (auto& p : e) {
      int x = get<1>(p);
      int y = get<2>(p);
      int z = get<0>(p);
      if (d.unite(x, y)) {
        ans += z;
        taken.push_back(p);
      } else {
        if (z == 0) {
          done = true;
        }
      }
    }
    long long res;
    if (!done) {
      res = ans + val;
      dsu dd(n);
      for (auto& p : taken) {
        int x = get<1>(p);
        int y = get<2>(p);
        int z = get<0>(p);
        if (z > 0) {
          dd.unite(x, y);
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (g[i][j] != 0 && dd.get(i) != dd.get(j)) {
            res = min(res, ans + g[i][j]);
          }
        }
      }
    } else {
      res = ans;
    }
    cout << res << '\n';
  }
  return 0;
}