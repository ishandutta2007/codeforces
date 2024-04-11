#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int L = 18;

template <class T>
struct fenwick_tree {

  T tree[N];

  void update(int a, T val) {
    for ( ; a < N; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  T query(int a, int b) {
    return query(b) - query(a - 1);
  }

};

vector<array<int, 2>> queries[N];
fenwick_tree<int> ft;
vector<int> buses[N];
int ans[N];

vector<int> adj[N];
int par[L][N];
int nxt[L][N];

int time_out[N];
int time_in[N];
int dep[N];
int timer;

int log_n;
int n;

bool ancestor(int u, int v) {
  return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
}

int lca(int u, int v) {
  if (ancestor(u, v)) {
    return u;
  }
  for (int i = log_n - 1; i >= 0; --i) {
    if (!ancestor(par[i][u], v)) {
      u = par[i][u];
    }
  }
  return par[0][u];
}

int process(int& u, int l) {
  int res = 0;
  for (int i = log_n - 1; i >= 0; --i) {
    if (!ancestor(nxt[i][u], l)) {
      u = nxt[i][u];
      res += 1 << i;
    }
  }
  return res + 1;
}

void dfs(int u) {
  time_in[u] = ++timer;
  for (int c : adj[u]) {
    dep[c] = dep[u] + 1;
    par[0][c] = u;
    dfs(c);
  }
  time_out[u] = timer;
}

void dfs_pull(int u) {
  for (int c : adj[u]) {
    dfs_pull(c);
    if (dep[nxt[0][u]] > dep[nxt[0][c]]) {
      nxt[0][u] = nxt[0][c];
    }
  }
}

void dfs_calc(int u) {
  vector<int> pre(queries[u].size());
  for (int i = 0; i < int(queries[u].size()); ++i) {
    int v = queries[u][i][0];
    pre[i] = ft.query(time_in[v], time_out[v]);
  }

  for (int v : buses[u]) {
    ft.update(time_in[v], 1);
  }

  for (int c : adj[u]) {
    dfs_calc(c);
  }

  for (int i = 0; i < int(queries[u].size()); ++i) {
    int v = queries[u][i][0];
    if (ft.query(time_in[v], time_out[v]) > pre[i]) {
      --ans[queries[u][i][1]];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  while ((1 << log_n) <= n) {
    ++log_n;
  }

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);
  time_out[0] = timer;
  for (int i = 1; i < log_n; ++i) {
    for (int j = 1; j <= n; ++j) {
      par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }

  iota(nxt[0] + 1, nxt[0] + n + 1, 1);

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (time_in[u] > time_in[v]) {
      swap(u, v);
    }
    buses[u].push_back(v);

    int l = lca(u, v);
    for (int i : {u, v}) {
      if (dep[nxt[0][i]] > dep[l]) {
        nxt[0][i] = l;
      }
    }
  }

  dfs_pull(1);
  for (int i = 1; i < log_n; ++i) {
    for (int j = 1; j <= n; ++j) {
      nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    if (time_in[u] > time_in[v]) {
      swap(u, v);
    }

    if (ancestor(u, v)) {
      ans[i] = process(v, u);
    } else {
      int l = lca(u, v);
      ans[i] += process(u, l) + process(v, l);
      assert(time_in[u] < time_in[v]);
      queries[u].push_back({v, i});
    }
  }

  dfs_calc(1);

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] < n ? ans[i] : -1) << "\n";
  }
}