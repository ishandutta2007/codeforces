#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
const int K = 50 + 1;

int par[K][N], sub[K][N], color[N];
array<int, 2> edges[N], query[N];
bool offset[K][N];

pair<int, bool> find(int c, int u) {
  bool x = false;
  while (u != par[c][u]) {
    x ^= offset[c][u];
    u = par[c][u];
  }
  return {u, x};
}

void solve(int l, int r, vector<array<int, 3>> &updates) {
  vector<array<int, 4>> undo;
  for (auto [a, b, i] : updates) {
    if (a <= l && r <= b) {
      int c = color[i];
      if (c > 0) {
        auto [u, cu] = find(c, edges[i][0]);
        auto [v, cv] = find(c, edges[i][1]);
        if (u != v) {
          if (sub[c][u] > sub[c][v]) {
            swap(u, v);
          }
          par[c][u] = v;
          sub[c][v] += sub[c][u];
          offset[c][u] = cu ^ cv ^ true;
          undo.push_back({c, u, v, cu ^ cv});
        }
      }
    }
  }

  if (l == r) {
    auto [i, c] = query[l];
    auto [u, cu] = find(c, edges[i][0]);
    auto [v, cv] = find(c, edges[i][1]);
    if (u != v || cu != cv) {
      cout << "YES\n";
      color[i] = c;
    } else {
      cout << "NO\n";
    }
  } else {
    int m = (l + r) / 2;
    vector<array<int, 3>> left, right;
    for (auto [a, b, i] : updates) {
      if (a > l || r > b) {
        if (a <= m) {
          left.push_back({a, b, i});
        }
        if (b > m) {
          right.push_back({a, b, i});
        }
      }
    }
    solve(l, m, left);
    solve(m + 1, r, right);
  }

  while (!undo.empty()) {
    auto [c, u, v, w] = undo.back();
    undo.pop_back();
    offset[c][u] = false;
    sub[c][v] -= sub[c][u];
    par[c][u] = u;
  }
}

int prv[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, q;
  cin >> n >> m >> k >> q;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i] = {--u, --v};
  }

  vector<array<int, 3>> updates;
  for (int i = 0; i < q; ++i) {
    int e, c;
    cin >> e >> c;
    query[i] = {--e, c};
    updates.push_back({prv[e], i, e});
    prv[e] = i + 1;
  }

  for (int i = 0; i < m; ++i) {
    if (prv[i] < q) {
      updates.push_back({prv[i], q - 1, i});
    }
  }

  for (int i = 1; i <= k; ++i) {
    fill(sub[i], sub[i] + n, 1);
    iota(par[i], par[i] + n, 0);
  }

  solve(0, q - 1, updates);
}