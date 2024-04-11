#include <bits/stdc++.h>
using namespace std;

struct bcc {

  vector<int> in, low, cur, color;
  vector<multiset<int>> adj;
  int n, m = 0, t = 0;

  bcc(int n) : n(n) {
    color.resize(n);
    low.resize(n);
    adj.resize(n);
    in.resize(n);
  }

  void add_edge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
  }

  vector<int> dfs(int u) {
    vector<int> me = {u};
    in[u] = low[u] = ++t;
    while (!adj[u].empty()) {
      int c = *adj[u].begin();
      adj[u].erase(adj[u].begin());
      adj[c].erase(adj[c].find(u));
      if (in[c] == 0) {
        vector<int> child = dfs(c);
        if (child.size() > me.size()) {
          swap(child, me);
        }
        me.insert(me.end(), child.begin(), child.end());
        low[u] = min(low[u], low[c]);
      } else {
        low[u] = min(low[u], in[c]);
      }
    }

    if (low[u] == in[u]) {
      for (auto v : me) {
        color[v] = m;
      }
      me.clear();
      ++m;
    }
    return me;
  }

  void solve() {
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) {
        dfs(i);
      }
    }
  }

};

const int N = 300000;
const int L = __lg(N) + 1;

array<int, 2> edge[N];
vector<int> adj[N];

int par[L][N], in[N], out[N], t, k;

void dfs(int u) {
  in[u] = ++t;
  for (auto c : adj[u]) {
    if (c != par[0][u]) {
      par[0][c] = u;
      dfs(c);
    }
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

  for (int i = __lg(k); i >= 0; --i) {
    if (par[i][u] != -1 && !ancestor(par[i][u], v)) {
      u = par[i][u];
    }
  }
  return par[0][u];
}

void process(vector<int> &v) {
  sort(v.begin(), v.end(), [&](int a, int b) {
    return in[a] < in[b];
  });
  v.erase(unique(v.begin(), v.end()), v.end());
}

int x[N], id[N], o, n;

int rotate(int y) {
  y = (y + o) % n;
  if (y == 0) {
    y = n;
  }
  return y - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, q;
  cin >> n >> m >> q;

  bcc linak(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edge[i] = {--u, --v};
    linak.add_edge(u, v);
  }
  linak.solve();
  k = linak.m;

  for (int i = 0; i < m; ++i) {
    auto [u, v] = edge[i];
    u = linak.color[u];
    v = linak.color[v];
    if (u != v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  for (int i = 0; i < k; ++i) {
    if (in[i] == 0) {
      par[0][i] = -1;
      dfs(i);
    }
  }

  for (int i = 1; i <= __lg(k); ++i) {
    for (int j = 0; j < k; ++j) {
      if (par[i - 1][j] == -1) {
        par[i][j] = -1;
      } else {
        par[i][j] = par[i - 1][par[i - 1][j]];
      }
    }
  }

  for (int z = 1; z <= q; ++z) {
    int nq, mq;
    cin >> nq >> mq;
    vector<int> nodes;

    for (int i = 0; i < nq; ++i) {
      cin >> x[i];
      x[i] = linak.color[rotate(x[i])];
      nodes.push_back(x[i]);
    }

    for (int i = 0; i < mq; ++i) {
      int u, v;
      cin >> u >> v;
      u = linak.color[rotate(u)];
      v = linak.color[rotate(v)];
      nodes.push_back(u);
      nodes.push_back(v);
      edge[i] = {u, v};
    }

    process(nodes);
    for (int i = 1, j = nodes.size(); i < j; ++i) {
      int u = lca(nodes[i - 1], nodes[i]);
      if (u != -1) {
        nodes.push_back(u);
      }
    }
    process(nodes);
    int r = nodes.size();

    vector<int> stk;
    bcc radewoosh(r);
    for (int i = 0; i < r; ++i) {
      while (!stk.empty() && !ancestor(stk.back(), nodes[i])) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        radewoosh.add_edge(id[stk.back()], i);
      }
      stk.push_back(nodes[i]);
      id[nodes[i]] = i;
    }

    for (int i = 0; i < mq; ++i) {
      auto [u, v] = edge[i];
      radewoosh.add_edge(id[u], id[v]);
    }
    radewoosh.solve();

    bool ok = true;
    int c = radewoosh.color[id[x[0]]];
    for (int i = 0; i < nq; ++i) {
      ok &= (c == radewoosh.color[id[x[i]]]);
    }

    cout << (ok ? "YES" : "NO") << "\n";
    if (ok) {
      o = (o + z) % n;
    }
  }
}