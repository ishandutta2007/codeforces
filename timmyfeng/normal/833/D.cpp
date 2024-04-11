#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(long long a) {
    val = a % M;
    if (val < 0) {
      val += M;
    }
  }

  int mod() {
    return M;
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

template <class T>
struct fenwick {

  vector<T> tree;
  int n;

  fenwick() {}

  fenwick(int n) : n(n) {
    tree.resize(n + 1);
  }

  void update(int a, T val) {
    for ( ; a <= n; a += a & -a) {
      tree[a] += val;
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
    for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

using mint = modint<1'000'000'007>;

const int N = 100'000;

vector<array<int, 3>> adj[N];
bool visited[N];
int sub[N];
int m;

fenwick<int> fenw[2];
int jelly[N][2];
mint clammy[N];
mint ans = 1;

mint pow(mint b, int e) {
  mint res = 1;
  while (e > 0) {
    if (e % 2 == 1) {
      res *= b;
    }
    b *= b;
    e /= 2;
  }
  return res;
}

void dfs_sub(int u, int p) {
  sub[u] = 1;
  for (auto [c, x, t] : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int p) {
  for (auto [c, x, t] : adj[u]) {
    if (c != p && !visited[c] && sub[c] > m / 2) {
      return dfs_find(c, u);
    }
  }
  return u;
}

void dfs_init(int u, int p) {
  for (auto [c, x, t] : adj[u]) {
    if (c != p && !visited[c]) {
      clammy[c] = clammy[u] * x;
      jelly[c][t] = jelly[u][t] + 2;
      jelly[c][t ^ 1] = jelly[u][t ^ 1] - 1;
      dfs_init(c, u);
    }
  }
}

void dfs_update(int u, int p, int val) {
  for (auto i : {0, 1}) {
    fenw[i].update(jelly[u][i] + m, val);
  }

  for (auto [c, x, t] : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_update(c, u, val);
    }
  }
}

void dfs_ans(int u, int p) {
  int cnt = fenw[0].query(3 * m);
  for (auto i : {0, 1}) {
    cnt -= fenw[i].query(-jelly[u][i] - 1 + m);
  }
  ans *= pow(clammy[u], cnt);

  for (auto [c, x, t] : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_ans(c, u);
    }
  }
}

void solve(int u) {
  dfs_sub(u, -1);
  m = sub[u];
  u = dfs_find(u, -1);

  for (auto i : {0, 1}) {
    fenw[i] = fenwick<int>(3 * m);
  }

  clammy[u] = 1;
  jelly[u][0] = 0;
  jelly[u][1] = 0;
  dfs_init(u, -1);
  dfs_update(u, -1, 1);

  for (auto [c, x, t] : adj[u]) {
    if (!visited[c]) {
      dfs_update(c, u, -1);
      dfs_ans(c, u);
      dfs_update(c, u, 1);
    }
  }

  visited[u] = true;
  for (auto [c, x, t] : adj[u]) {
    if (!visited[c]) {
      solve(c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, x, t;
    cin >> u >> v >> x >> t;
    --u, --v;
    adj[u].push_back({v, x, t});
    adj[v].push_back({u, x, t});
  }

  solve(0);

  cout << ans.val << "\n";
}