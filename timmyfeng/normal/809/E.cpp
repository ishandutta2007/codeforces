#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
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

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
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

using mint = modint<1'000'000'007>;
const int N = 200'000 + 1;

mint mod_inv[N];

vector<int> factors[N];
vector<int> keys[N];
int phi[N];
int a[N];

vector<int> adj[N];
bool visited[N];
int depth[N];
int sub[N];

mint multiples[N];
mint ans;

void dfs_sub(int u, int p) {
  sub[u] = 1;
  for (auto c : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int p, int n) {
  for (auto c : adj[u]) {
    if (c != p && !visited[c] && sub[c] > n / 2) {
      return dfs_find(c, u, n);
    }
  }
  return u;
}

void dfs_depth(int u, int p) {
  for (auto c : adj[u]) {
    if (c != p && !visited[c]) {
      depth[c] = depth[u] + 1;
      dfs_depth(c, u);
    }
  }
}

void dfs_add(int u, int p, int sign) {
  for (auto c : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_add(c, u, sign);
    }
  }

  int size = factors[a[u]].size();
  for (int i = 0; i < (1 << size); ++i) {
    multiples[keys[a[u]][i]] += phi[a[u]] * sign;
  }
}

void dfs_process(int u, int p) {
  for (auto c : adj[u]) {
    if (c != p && !visited[c]) {
      dfs_process(c, u);
    }
  }

  int size = factors[a[u]].size();
  vector<mint> sum(1 << size);
  for (int i = 0; i < (1 << size); ++i) {
    sum[i] = multiples[keys[a[u]][i]];
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < (1 << size); ++j) {
      if ((j & (1 << i)) > 0) {
        sum[j ^ (1 << i)] -= sum[j];
      }
    }
  }

  for (int i = 0; i < (1 << size); ++i) {
    mint cost = sum[i] * phi[a[u]] * depth[u];
    cost *= keys[a[u]][i] * mod_inv[phi[keys[a[u]][i]]];
    ans += cost;
  }
}

void solve(int u) {
  dfs_sub(u, -1);
  u = dfs_find(u, -1, sub[u]);
  depth[u] = 0;
  dfs_depth(u, -1);

  dfs_add(u, -1, 1);
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs_add(c, u, -1);
      dfs_process(c, u);
      dfs_add(c, u, 1);
    }
  }
  dfs_add(u, -1, -1);

  visited[u] = true;

  for (auto c : adj[u]) {
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

  iota(phi, phi + n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (factors[i].empty() && i > 1) {
      for (int j = i; j <= n; j += i) {
        phi[j] = phi[j] / i * (i - 1);
        factors[j].push_back(i);
      }
    }

    int size = factors[i].size();
    keys[i].assign(1 << size, 1);
    for (int j = 0; j < (1 << size); ++j) {
      for (int k = 0; k < size; ++k) {
        if ((j & (1 << k)) > 0) {
          keys[i][j] *= factors[i][k];
        }
      }
    }

    mod_inv[i] = mint(i).inv();
  }

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(0);

  cout << (ans * 2 * mod_inv[n] * mod_inv[n - 1]).val << "\n";
}