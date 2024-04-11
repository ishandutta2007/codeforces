#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *left = nullptr, *right = nullptr;
  long long hash = 0;

  void push() {
    if (left == nullptr) {
      left = new segtree();
      right = new segtree();
    }
  }

  segtree * update(int a, long long x, int l, int r) {
    segtree *u = new segtree();
    if (l == r) {
      u->hash = hash ^ x;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        u->left = left->update(a, x, l, m), u->right = right;
      } else {
        u->right = right->update(a, x, m + 1, r), u->left = left;
      }
      u->hash = u->left->hash ^ u->right->hash;
    }
    return u;
  }

  long long query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return hash;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return left->query(a, b, l, m) ^ right->query(a, b, m + 1, r);
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300000 + 1;
const int L = __lg(N) + 1;

long long code[N];
segtree *path[N];
int a[N], n;

int par[L][N], in[N], out[N], t;
vector<int> adj[N];

void dfs(int u) {
  in[u] = ++t;
  path[u] = path[u]->update(a[u], code[a[u]], 1, n);
  for (auto c : adj[u]) {
    if (c != par[0][u]) {
      path[c] = path[u];
      par[0][c] = u;
      dfs(c);
    }
  }
  out[u] = t;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[u] >= out[v];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    code[i] = rng();
  }

  path[1] = new segtree();
  dfs(1), out[0] = t;

  for (int i = 1; i <= __lg(n); ++i) {
    for (int j = 1; j <= n; ++j) {
      par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }

  while (q--) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;

    int p = u;
    if (!ancestor(u, v)) {
      for (int i = __lg(n); i >= 0; --i) {
        if (!ancestor(par[i][p], v)) {
          p = par[i][p];
        }
      }
      p = par[0][p];
    }

    int lo = l, hi = r + 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;

      long long hash = path[u]->query(l, mid, 1, n) ^ path[v]->query(l, mid, 1, n);
      if (a[p] >= l && a[p] <= mid) {
        hash ^= code[a[p]];
      }

      if (hash == 0) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    cout << (lo <= r ? lo : -1) << "\n";
  }
}