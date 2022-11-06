#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;

  set<int> s = {-1, N};
  for (int i = 0; i < N; ++i) {
    s.insert(i);
  }

  vector<map<int, int>> tree(N * 4);

  auto Insert = [&](int ql, int qr) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (l >= qr || ql >= r) {
        return;
      }
      if (l >= ql && r <= qr) {
        auto iter = tree[o].upper_bound(qr);
        if (iter != tree[o].begin() && prev(iter)->second >= ql) {
          return;
        }
        while (iter != tree[o].end() && iter->second <= ql) {
          iter = tree[o].erase(iter);
        }
        tree[o][qr] = ql;
        return;
      }
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
    };

    return dfs(dfs, 0, N);
  };

  auto Query = [&](int ql, int qr, int p) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> bool {
      auto iter = tree[o].upper_bound(qr);
      if (iter != tree[o].begin() && prev(iter)->second >= ql) {
        return true;
      }
      if (r - l == 1) {
        return false;
      }
      int m = (l + r) >> 1;
      if (p < m) {
        return dfs(dfs, l, m, o * 2 + 1);
      } else {
        return dfs(dfs, m, r, o * 2 + 2);
      }
    };

    return dfs(dfs, 0, N);
  };

  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      if (x == 0) {
        auto iter = s.lower_bound(l);
        while (iter != s.end() && *iter < r) {
          iter = s.erase(iter);
        }
      } else {
        Insert(l, r);
      }
    } else {
      int x;
      cin >> x;
      x--;
      if (!s.count(x)) {
        cout << "NO\n";
      } else {
        auto iter = s.upper_bound(x);
        assert(iter != s.end());
        int r = *iter;
        assert(iter != s.begin() && prev(iter) != s.begin());
        int l = *prev(prev(iter));
        cout << (Query(l + 1, r, x) ? "YES" : "N/A") << "\n";
      }
    }
  }
  return 0;
}