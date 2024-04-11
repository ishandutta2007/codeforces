/**
 *    author:  tourist
 *    created: 30.05.2021 18:27:31       
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 17;

struct segtree {

  set<pair<int, int>> tree[2 * MAX];

  segtree() {
  }

  bool is_good(int v, int x, int y) {
    auto it = tree[v].lower_bound(make_pair(x, -1));
    return (it != tree[v].end() && it->second <= y);
  }

  int find_first(int x, int y) {
    int v = 1;
    if (!is_good(v, x, y)) {
      return -1;
    }
    while (v < MAX) {
      if (is_good(2 * v, x, y)) {
        v = 2 * v;
      } else {
//        assert(is_good(2 * v + 1, x, y));
        v = 2 * v + 1;
      }
    }
    return v - MAX;
  }

  void add(int v, int x, int y) {
    v += MAX;
    while (v > 0) {
      auto it = tree[v].lower_bound(make_pair(x + 1, -1));
      if (it != tree[v].end() && it->second <= y) {
        // pass
      } else {
        while (it != tree[v].begin()) {
          --it;
          if (it->second < y) {
            break;
          }
          it = tree[v].erase(it);
        }
        tree[v].emplace(x, y);
      }
      v /= 2;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  vector<vector<int>> by_len(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
    by_len[r[i] - l[i] + 1].push_back(i);
  }
  segtree st;
  vector<int> res(n + 1);
  for (int x = n; x >= 1; x--) {
    for (int i : by_len[x]) {
      st.add(i, l[i], r[i]);
    }
    function<void(int, int)> Solve = [&](int from, int to) {
      if (to - from + 1 < x) {
        return;
      }
      int u = st.find_first(from, to);
      if (u == -1) {
        return;
      }
      res[x] += r[u] - l[u] + 1;
      Solve(from, l[u] - 1);
      Solve(r[u] + 1, to);
    };
    Solve(0, n - 1);
  }
  for (int x = 1; x <= n; x++) {
    cout << res[x] << '\n';
  }
  return 0;
}