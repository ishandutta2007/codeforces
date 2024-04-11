#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<pair<int, int>> chd[N];
vector<int> adj[N];
int time_out[N];
int time_in[N];
int timer, n;

struct segment_tree {

  struct node {
    int max = 0, cnt = 0, lazy = 0;
    void apply(int l, int r, int val) {
      max += val;
      lazy += val;
    }
  } tree[N * 4];

  node combine(const node& a, const node& b) {
    node c;
    if (a.max >= b.max) {
      c.max = a.max;
      c.cnt += a.cnt;
    }
    if (b.max >= a.max) {
      c.max = b.max;
      c.cnt += b.cnt;
    }
    return c;
  }

  void push(int v, int l, int r) {
    int m = (l + r) / 2;
    tree[v * 2].apply(l, m, tree[v].lazy);
    tree[v * 2 + 1].apply(m + 1, r, tree[v].lazy);
  }

  void pull(int v) {
    tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
  }

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v].cnt = 1;
    } else {
      int m = (l + r) / 2;
      build(v * 2, l, m);
      build(v * 2 + 1, m + 1, r);
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

  template <class... T>
  void update(int a, int b, const T&... val) {
    update(1, 1, n, a, b, val...);
  }

} st;

void dfs(int u, int p) {
  time_in[u] = ++timer;
  for (int c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      chd[u].emplace_back(time_out[c], c);
    }
  }
  time_out[u] = timer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  st.build(1, 1, n);

  set<pair<int, int>> edges;
  while (q--) {
    int u, v;
    cin >> u >> v;

    if (time_in[u] > time_in[v]) {
      swap(u, v);
    }

    int type = 1;
    if (edges.count({u, v}) == 1) {
      edges.erase({u, v});
      type = -1;
    } else {
      edges.insert({u, v});
    }

    if (time_out[u] >= time_out[v]) {
      int c = lower_bound(chd[u].begin(), chd[u].end(), make_pair(time_in[v], 0))->second;
      st.update(1, n, type);
      st.update(time_in[c], time_out[c], -type);
    } else {
      st.update(time_in[u], time_out[u], type);
    }
    st.update(time_in[v], time_out[v], type);

    if (st.tree[1].max == int(edges.size())) {
      cout << st.tree[1].cnt << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}