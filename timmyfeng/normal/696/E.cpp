#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  pair<long long, int> mini;
  queue<int> girls;
  long long lazy;

  segtree() {
    mini = {LLONG_MAX, 0};
    lazy = 0;
  }

  void apply(long long value) {
    if (mini.first < LLONG_MAX) {
      mini.first += value;
    }
    lazy += value;
  }

  void pull() {
    mini = min(right->mini, left->mini);
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (lazy != 0) {
      right->apply(lazy);
      left->apply(lazy);
      lazy = 0;
    }
  }

  void add(int a, int i, int l, int r) {
    if (l == r) {
      girls.push(i);
      i = girls.front();
      mini = {i + lazy, i};
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        left->add(a, i, l, m);
      } else {
        right->add(a, i, m + 1, r);
      }
      pull();
    }
  }

  void sub(int a, int l, int r) {
    if (l == r) {
      girls.pop();
      if (girls.empty()) {
        mini = {LLONG_MAX, 0};
      } else {
        int i = girls.front();
        mini = {i + lazy, i};
      }
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        left->sub(a, l, m);
      } else {
        right->sub(a, m + 1, r);
      }
      pull();
    }
  }

  void update(int a, int b, long long value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(value);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, value, l, m);
      right->update(a, b, value, m + 1, r);
      pull();
    }
  }

  pair<long long, int> query(int a, int b, int l, int r) {
    if (b < l || r < a) {
      return {LLONG_MAX, 0};
    } else if (a <= l && r <= b) {
      return mini;
    } else {
      push();
      int m = (l + r) / 2;
      return min(left->query(a, b, l, m), right->query(a, b, m + 1, r));
    }
  }

};

const int N = 100000 + 1;

vector<int> adj[N];
int sub[N], par[N];

void dfs_sub(int u) {
  sub[u] = 1;
  for (auto &c : adj[u]) {
    adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
    par[c] = u;

    dfs_sub(c);
    sub[u] += sub[c];
    int &v = adj[u][0];
    if (sub[c] > sub[v]) {
      swap(c, v);
    }
  }
}

int in[N], out[N], root[N], timer;

void dfs_hld(int u) {
  in[u] = ++timer;
  for (auto c : adj[u]) {
    root[c] = (c == adj[u][0]) ? root[u] : c;
    dfs_hld(c);
  }
  out[u] = timer;
}

int where[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  root[1] = 1;
  dfs_sub(1);
  dfs_hld(1);
  segtree *nyc = new segtree();

  for (int i = 1; i <= m; ++i) {
    cin >> where[i];
    nyc->add(in[where[i]], i, 1, n);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v, k;
      cin >> u >> v >> k;

      vector<int> ans;
      while (k--) {
        pair<long long, int> a = {LLONG_MAX, 0};
        int x = u, y = v;

        while (root[x] != root[y]) {
          if (in[x] > in[y]) {
            swap(x, y);
          }
          a = min(a, nyc->query(in[root[y]], in[y], 1, n));
          y = par[root[y]];
        }

        if (in[x] > in[y]) {
          swap(x, y);
        }
        a = min(a, nyc->query(in[x], in[y], 1, n));

        if (a.second == 0) {
          break;
        }
        ans.push_back(a.second);
        nyc->sub(in[where[a.second]], 1, n);
      }

      cout << ans.size() << " ";
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      int u, k;
      cin >> u >> k;
      nyc->update(in[u], out[u], k, 1, n);
    }
  }
}