#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  array<int, 2> mini;

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }
  }

  void update(int a, int x, int l, int r) {
    if (l == r) {
      mini = {x, l};
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        left->update(a, x, l, m);
      } else {
        right->update(a, x, m + 1, r);
      }
      mini = min(left->mini, right->mini);
    }
  }

  array<int, 2> query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return mini;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return min(left->query(a, b, l, m), right->query(a, b, m + 1, r));
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

const int N = 100000 + 1;

int values[N], prv[N], dist[N];
vector<array<int, 2>> todo[N];
array<int, 4> spell[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (auto &j : spell[i]) {
      cin >> j;
    }
    values[i] = spell[i][0];
  }

  sort(values, values + n + 1);
  int m = unique(values, values + n + 1) - values;

  for (int i = 1; i <= n; ++i) {
    int j = lower_bound(values, values + m, spell[i][0]) - values;
    todo[j].push_back({spell[i][1], i});
  }

  segtree *board = new segtree();
  for (int i = 0; i < m; ++i) {
    todo[i].push_back({INT_MAX, 0});
    sort(todo[i].rbegin(), todo[i].rend());
    board->update(i, todo[i].back()[0], 0, m - 1);
  }

  queue<int> que;
  que.push(0);

  while (!que.empty()) {
    int u = que.front();
    int x = spell[u][2];
    int y = spell[u][3];
    que.pop();

    int v = upper_bound(values, values + m, x) - values - 1;
    while (true) {
      auto [b, i] = board->query(0, v, 0, m - 1);
      if (b > y) {
        break;
      }

      int c = todo[i].back()[1];
      dist[c] = dist[u] + 1;
      prv[c] = u;
      que.push(c);

      todo[i].pop_back();

      board->update(i, todo[i].back()[0], 0, m - 1);
    }
  }

  if (dist[n] == 0) {
    cout << -1 << "\n";
    exit(0);
  }

  cout << dist[n] << "\n";

  vector<int> path;
  while (n > 0) {
    path.push_back(n);
    n = prv[n];
  }

  for (int i = path.size() - 1; i >= 0; --i) {
    cout << path[i] << " ";
  }
  cout << "\n";
}