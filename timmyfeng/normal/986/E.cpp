#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int A = 1e7 + 1;
const int M = 1e9 + 7;
const int L = 19;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

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

};

struct path {
  int u, v, l, p;
} paths[N];

struct request {
  int power, type, i;
  bool operator<(request oth) {
    return make_pair(power, type) < make_pair(oth.power, oth.type);
  }
};

vector<request> queries[A];
fenwick_tree<int> ft;

vector<int> adj[N];
int sieve[A];
int ans[N];

int time_out[N];
int time_in[N];
int par[L][N];
int log_n;
int timer;

void dfs(int u, int p) {
  time_in[u] = ++timer;
  for (int c : adj[u]) {
    if (c != p) {
      par[0][c] = u;
      dfs(c, u);
    }
  }
  time_out[u] = timer;
}

bool is_ancestor(int u, int v) {
  return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  for (int i = log_n - 1; i >= 0; --i) {
    if (!is_ancestor(par[i][u], v)) {
      u = par[i][u];
    }
  }
  return par[0][u];
}

vector<pair<int, int>> get(int a) {
  vector<pair<int, int>> res;
  while (a > 1) {
    int cnt = 0;
    int cur = sieve[a];
    while (a % cur == 0) {
      a /= cur;
      ++cnt;
    }
    res.emplace_back(cur, cnt);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < A; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    for (auto [p, cnt] : get(a)) {
      for (int j = 1; j <= cnt; ++j) {
        queries[p].push_back({j, 0, i});
      }
    }
  }

  dfs(1, 0);
  time_out[0] = timer;
  for (log_n = 1; (1 << log_n) < 2 * n; ++log_n) {
    for (int i = 1; i <= n; ++i) {
      par[log_n][i] = par[log_n - 1][par[log_n - 1][i]];
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> paths[i].u >> paths[i].v;
    paths[i].l = lca(paths[i].u, paths[i].v);
    paths[i].p = par[0][paths[i].l];

    int x;
    cin >> x;
    for (auto [p, cnt] : get(x)) {
      queries[p].push_back({cnt, 1, i});
    }

    ans[i] = 1;
  }

  for (int i = 1; i < A; ++i) {
    sort(queries[i].begin(), queries[i].end());
    for (request r : queries[i]) {
      if (r.type == 0) {
        ft.update(time_in[r.i], 1);
        ft.update(time_out[r.i] + 1, -1);
      } else {
        int cnt = 0;
        cnt += ft.query(time_in[paths[r.i].u]);
        cnt += ft.query(time_in[paths[r.i].v]);
        cnt -= ft.query(time_in[paths[r.i].l]);
        cnt -= ft.query(time_in[paths[r.i].p]);
        ans[r.i] = mul(ans[r.i], mod_pow(i, cnt));
      }
    }

    for (request r : queries[i]) {
      if (r.type == 0) {
        ft.update(time_in[r.i], -1);
        ft.update(time_out[r.i] + 1, 1);
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}