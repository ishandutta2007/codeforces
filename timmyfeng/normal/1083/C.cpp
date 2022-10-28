#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int L = 19;

vector<int> adj[N];
int perm_inv[N];
int perm[N];
int n;

int euler_tour[N * 2];
int time_out[N];
int time_in[N];
int dep[N];
int timer;

void dfs(int u) {
  euler_tour[++timer] = u;
  time_in[u] = timer;
  for (int c : adj[u]) {
    dep[c] = dep[u] + 1;
    dfs(c);
    euler_tour[++timer] = u;  
  }
  time_out[u] = timer;
}

bool is_ancestor(int u, int v) {
  return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

struct sparse_table {

  int table[L][N * 2];

  void init() {
    for (int i = 1; i <= 2 * n; ++i) {
      table[0][i] = euler_tour[i];
    }
    for (int i = 1; (1 << i) < 2 * n; ++i) {
      int len = 1 << (i - 1);
      for (int j = 1; j + len <= 2 * n; ++j) {
        if (dep[table[i - 1][j]] < dep[table[i - 1][j + len]]) {
          table[i][j] = table[i - 1][j];
        } else {
          table[i][j] = table[i - 1][j + len];
        }
      }
    }
  }

  int query(int a, int b) {
    if (a > b) {
      swap(a, b);
    }
    int log_l = 31 - __builtin_clz(b - a + 1);
    if (dep[table[log_l][a]] < dep[table[log_l][b - (1 << log_l) + 1]])
      return table[log_l][a];
    return table[log_l][b - (1 << log_l) + 1];
  }

} sparse;

struct segment_tree {

  struct node {
    int endpoint[2];
    int lca = 0;
    bool ok;
    void apply(int l, int r, int u) {
      endpoint[0] = u;
      endpoint[1] = u;
      ok = true;
      lca = u;
    }
  } tree[N * 4];

  int nodes[4];

  node combine(const node& a, const node& b) {
    if (a.lca == 0)
      return b;
    if (b.lca == 0)
      return a;

    node c;
    c.lca = sparse.query(time_in[a.lca], time_in[b.lca]);
    c.ok = a.ok && b.ok;
    if (!c.ok)
      return c;

    for (int i = 0; i < 2; ++i) {
      nodes[i] = a.endpoint[i];
      nodes[i + 2] = b.endpoint[i];
    }

    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        bool ok = (sparse.query(time_in[nodes[i]], time_in[nodes[j]]) == c.lca);
        for (int k = 0; k < 4 && ok; ++k) {
          ok &= (is_ancestor(nodes[k], nodes[i]) || is_ancestor(nodes[k], nodes[j]));
        }
        if (ok) {
          c.endpoint[0] = nodes[i];
          c.endpoint[1] = nodes[j];
          return c;
        }
      }
    }

    c.ok = false;
    return c;
  }

  void push(int v, int l, int r) {
    int m = (l + r) / 2;
  }

  void pull(int v) {
    tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
  }

  template <class T>
  void build(int v, int l, int r, const T& a) {
    if (l == r) {
      tree[v].apply(l, r, a[l]);
    } else {
      int m = (l + r) / 2;
      build(v * 2, l, m, a);
      build(v * 2 + 1, m + 1, r, a);
      pull(v);
    }
  }

  template <class... T>
  void update(int v, int l, int r, int a, int b, const T&... val) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      tree[v].apply(l, r, val...);
    } else {
      push(v, l, r);
      int m = (l + r) / 2;
      update(v * 2, l, m, a, b, val...);
      update(v * 2 + 1, m + 1, r, a, b, val...);
      pull(v);
    }
  }

  int find_last(int v, int l, int r, node& pre) {
    node res = combine(pre, tree[v]);
    int m = (l + r) / 2;
    if (res.ok) {
      pre = res;
      return r;
    } else if (l == r) {
      return l - 1;
    } else {
      int chd = find_last(v * 2, l, m, pre);
      return chd == m ? find_last(v * 2 + 1, m + 1, r, pre) : chd;
    }
  }

  template <class... T>
  void update(int a, const T&... val) {
    update(1, 0, n - 1, a, a, val...);
  }

  int find_last() {
    node pre;
    return find_last(1, 0, n - 1, pre);
  }

} st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
    perm_inv[perm[i]] = i;
  }

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);
  sparse.init();
  st.build(1, 0, n - 1, perm_inv);

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, j;
      cin >> i >> j;
      swap(perm[i], perm[j]);
      st.update(perm[i], i);
      st.update(perm[j], j);
    } else {
      cout << st.find_last() + 1 << "\n";
    }
  }
}