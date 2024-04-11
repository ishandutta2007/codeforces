#include <bits/stdc++.h>
using namespace std;

struct diameter {

  int u, l, ul, lv, ulv;

  diameter() {
    u = INT_MIN / 2;
    l = INT_MIN / 2;
    ul = INT_MIN / 2;
    lv = INT_MIN / 2;
    ulv = INT_MIN / 2;
  }

  diameter(int depth) {
    u = depth;
    l = -2 * depth;
    ul = -depth;
    lv = -depth;
    ulv = 0;
  }

};

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  diameter paths[2];
  bool flip;

  void apply(int depth) {
    paths[0] = diameter(depth);
    paths[1].l = -2 * depth;
  }

  void apply() {
    swap(paths[0], paths[1]);
    flip ^= true;
  }

  void pull() {
    for (int i = 0; i < 2; ++i) {
      paths[i].u = max(right->paths[i].u, left->paths[i].u);
      paths[i].l = max(right->paths[i].l, left->paths[i].l);

      paths[i].ul = max({
          right->paths[i].ul,
          left->paths[i].ul,
          left->paths[i].u + right->paths[i].l
      });

      paths[i].lv = max({
          right->paths[i].lv,
          left->paths[i].lv,
          left->paths[i].l + right->paths[i].u
      });

      paths[i].ulv = max({
          right->paths[i].ulv,
          left->paths[i].ulv,
          left->paths[i].ul + right->paths[i].u,
          left->paths[i].u + right->paths[i].lv
      });
    }
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (flip) {
      right->apply();
      left->apply();
      flip = false;
    }
  }

};

const int N = 500000;

vector<array<int, 2>> adj[N];
int depth[N];

int tour[2 * N];
int time_out[N];
int time_in[N];
int timer;

int vertex[N];
int t[N];

void build(segtree *u, int l, int r) {
  if (l == r) {
    u->apply(depth[tour[l]]);
  } else {
    u->push();
    int m = (l + r) / 2;
    build(u->left, l, m);
    build(u->right, m + 1, r);
    u->pull();
  }
}

void update(segtree *u, int l, int r, int a, int b) {
  if (b < l || r < a) {
    return;
  } else if (a <= l && r <= b) {
    u->apply();
  } else {
    u->push();
    int m = (l + r) / 2;
    update(u->left, l, m, a, b);
    update(u->right, m + 1, r, a, b);
    u->pull();
  }
}

void dfs(int u, int p) {
  time_out[u] = timer;
  time_in[u] = timer;
  tour[timer++] = u;
  for (auto [c, i] : adj[u]) {
    if (c != p) {
      depth[c] = depth[u] + 1;
      vertex[i] = c;
      dfs(c, u);
      time_out[u] = timer;
      tour[timer++] = u;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v >> t[i];
    --u, --v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  dfs(0, -1);

  segtree *villages = new segtree();
  build(villages, 0, 2 * n - 2);
  for (int i = 0; i < n - 1; ++i) {
    if (t[i] == 1) {
      int u = vertex[i];
      update(villages, 0, 2 * n - 2, time_in[u], time_out[u]);
    }
  }

  int m;
  cin >> m;

  while (m--) {
    int u;
    cin >> u;
    u = vertex[u - 1];
    update(villages, 0, 2 * n - 2, time_in[u], time_out[u]);
    cout << max(villages->paths[0].ulv, villages->paths[1].ulv) << "\n";
  }
}