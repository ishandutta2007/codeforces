#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> sz;

  union_find(int n) {
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
    return true;
  }

};

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;
  int tree = 0, back;

  segtree() : back(INT_MAX) {}

  void pull() {
    tree = max(left->tree, right->tree);
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }
    left->back = min(left->back, back);
    right->back = min(right->back, back);
  }

  void update(int a, int w, int l, int r) {
    if (l == r) {
      tree = w;
    } else {
      int m = (l + r) / 2;
      push();
      if (a <= m) {
        left->update(a, w, l, m);
      } else {
        right->update(a, w, m + 1, r);
      }
      pull();
    }
  }

  array<int, 2> query(int a, int b, int w, int l, int r) {
    if (b < l || r < a) {
      return {0, INT_MAX};
    } else if (a <= l && r <= b) {
      back = min(back, w);
      return {tree, back};
    } else {
      push();
      int m = (l + r) / 2;
      auto [tree_l, back_l] = left->query(a, b, w, l, m);
      auto [tree_r, back_r] = right->query(a, b, w, m + 1, r);
      pull();
      return {max(tree_l, tree_r), min(back_l, back_r)};
    }
  }

};

const int N = 200000;
const int L = __lg(N) + 1;

vector<array<int, 3>> adj[N];
int par[N][L];
int root[N];
int sub[N];
int out[N];
int in[N];
int n, t;

void dfs_sub(int u) {
  for (int i = 1; i <= __lg(n); ++i) {
    if (par[u][i - 1] == -1) {
      par[u][i] = -1;
    } else {
      par[u][i] = par[par[u][i - 1]][i - 1];
    }
  }

  sub[u] = 1;
  for (auto &v : adj[u]) {
    auto [c, w, e] = v;
    adj[c].erase(find(adj[c].begin(), adj[c].end(), array<int, 3>{u, w, e}));
    par[c][0] = u;
    dfs_sub(c);
    sub[u] += sub[c];
    if (sub[c] > sub[adj[u][0][0]]) {
      swap(v, adj[u][0]);
    }
  }
}

void dfs_hld(int u) {
  in[u] = t++;
  for (auto [c, w, e] : adj[u]) {
    root[c] = c == adj[u][0][0] ? root[u] : c;
    dfs_hld(c);
  }
  out[u] = t;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
  if (ancestor(u, v)) {
    return u;
  }

  for (int i = __lg(n); i >= 0; --i) {
    if (par[u][i] != -1 && !ancestor(par[u][i], v)) {
      u = par[u][i];
    }
  }
  return par[u][0];
}

template <class F>
void path_operation(int u, int v, F func) {
  int l = lca(u, v);
  for (int z = 0; z < 2; ++z) {
    while (!ancestor(root[u], l)) {
      func(in[root[u]], in[u]);
      u = par[root[u]][0];
    }
    if (in[l] + 1 <= in[u]) {
      func(in[l] + 1, in[u]);
    }
    swap(u, v);
  }
}

array<int, 4> edges[N];
bool back_edge[N];

int tree[N];
int ans[N];
int id[N];

void dfs(int u) {
  for (auto [c, w, e] : adj[u]) {
    tree[c] = w;
    id[c] = e;
    dfs(c);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    for (int j = 2; j >= 0; --j) {
      cin >> edges[i][j];
      --edges[i][j];
    }
    edges[i][3] = i;
  }
  sort(edges, edges + m);

  union_find dsu(n);
  for (int i = 0; i < m; ++i) {
    auto [w, u, v, e] = edges[i];
    if (dsu.unite(u, v)) {
      adj[u].push_back({v, w, e});
      adj[v].push_back({u, w, e});
    } else {
      back_edge[i] = true;
    }
  }

  par[0][0] = -1;
  dfs_sub(0);
  dfs_hld(0);
  dfs(0);

  segtree *max_min = new segtree();
  for (int i = 1; i < n; ++i) {
    max_min->update(in[i], tree[i], 0, n - 1);
  }

  for (int i = 0; i < m; ++i) {
    if (back_edge[i]) {
      auto [w, u, v, e] = edges[i];
      path_operation(u, v, [&](int a, int b) {
        ans[e] = max(ans[e], max_min->query(a, b, w, 0, n - 1)[0]);
      });
    }
  }

  for (int i = 1; i < n; ++i) {
    ans[id[i]] = max_min->query(in[i], in[i], INT_MAX, 0, n - 1)[1];
  }

  for (int i = 0; i < m; ++i) {
    cout << (ans[i] == INT_MAX ? -1 : ans[i]) << " ";
  }
  cout << "\n";
}