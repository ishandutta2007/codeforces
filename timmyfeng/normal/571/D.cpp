#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick {

  vector<T> tree;
  int n;

  fenwick(int n) : n(n) {
    tree.resize(n + 1);
  }

  void update(int a, T x) {
    for ( ; a <= n; a += a & -a) {
      tree[a] += x;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a > 0; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  int lower_bound(T k) {
    int res = 0;
    T cur = 0;
    for (int i = __lg(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

const int N = 500000 + 1;

vector<int> adj_u[N], adj_m[N];
bool par_u[N], par_m[N];
int in[N], out[N], t;

void dfs(int u, vector<int> *adj) {
  in[u] = out[u] = ++t;
  for (auto c : adj[u]) {
    dfs(c, adj);
  }
}

vector<int> subtract[N], queries[N];
long long ans[N];
char type[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    cin >> type[i];
    if (type[i] == 'U') {
      int u, v;
      cin >> u >> v;
      adj_u[u].push_back(v);
      queries[i] = {u, v};
      par_u[v] = true;
    } else if (type[i] == 'M') {
      int u, v;
      cin >> u >> v;
      adj_m[u].push_back(v);
      queries[i] = {u, v};
      par_m[v] = true;
    } else {
      int q;
      cin >> q;
      queries[i] = {q};
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!par_m[i]) {
      dfs(i, adj_m);
    }
  }

  map<int, int> latest;
  for (int i = 1; i <= n; ++i) {
    latest[i] = 0;
  }

  for (int i = 1; i <= m; ++i) {
    int u = queries[i][0];
    if (type[i] == 'M') {
      int v = queries[i][1];
      out[u] = out[v];
    } else if (type[i] == 'Z') {
      auto it = latest.find(in[u]);
      while (next(it) != latest.end() && next(it)->first <= out[u]) {
        latest.erase(next(it));
      }
      it->second = i;
    } else if (type[i] == 'Q') {
      int prv = prev(latest.upper_bound(in[u]))->second;
      if (prv > 0) {
        subtract[prv].push_back(i);
      }
    }
  }

  t = 0;
  for (int i = 1; i <= n; ++i) {
    if (!par_u[i]) {
      dfs(i, adj_u);
    }
  }

  fenwick<long long> fenw(n);
  for (int i = 1; i <= m; ++i) { 
    int u = queries[i][0];
    if (type[i] == 'U') {
      int v = queries[i][1];
      out[u] = out[v];
    } else if (type[i] == 'A') {
      int k = out[u] - in[u] + 1;
      fenw.update(in[u], k);
      fenw.update(out[u] + 1, -k);
    } else if (type[i] == 'Q') {
      ans[i] += fenw.query(in[u]);
      cout << ans[i] << "\n";
    }

    for (auto j : subtract[i]) {
      int k = queries[j][0];
      ans[j] -= fenw.query(in[k]);
    }
  }
}