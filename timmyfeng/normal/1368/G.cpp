#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  bool lazy = false;
  int sum = 0;

  segtree * update(int a, int b, int l, int r) {
    if (b < l || r < a) {
      return this;
    } else if (a <= l && r <= b) {
      segtree *res = new segtree();
      res->sum = r - l + 1;
      res->lazy = true;
      return res;
    } else {
      if (left == nullptr) {
        right = new segtree();
        left = new segtree();
      }

      int m = (l + r) / 2;
      if (lazy) {
        lazy = false;
        left->lazy = true;
        left->sum = m - l + 1;
        right->lazy = true;
        right->sum = r - m;
      }

      segtree *res = new segtree();
      res->left = left->update(a, b, l, m);
      res->right = right->update(a, b, m + 1, r);
      res->sum = res->left->sum + res->right->sum;
      return res;
    }
  }

};

const int N = 200000;

int in[N], out[N], sub[N], timer;
vector<int> adj[2][N];

void dfs_even(int u, int p = -1) {
  in[u] = ++timer;
  sub[u] = 1;
  for (auto c : adj[0][u]) {
    if (c != p) {
      dfs_even(c, u);
      sub[u] += sub[c];
    }
  }
  out[u] = timer;
}

segtree *tree;
long long ans;
int d;

void dfs_odd(int u, int p = -1) {
  tree = tree->update(in[u], out[u], 1, d);
  segtree *cur = tree;
  ans += tree->sum;
  for (auto c : adj[1][u]) {
    if (c != p) {
      dfs_odd(c, u);
      tree = cur;
    }
  }
}

vector<int> id[N], roots[2];
string grid[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    id[i].resize(m);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'U') {
        id[i][j] = id[i + 1][j] = d++;
      } else if (grid[i][j] == 'L') {
        id[i][j] = id[i][j + 1] = d++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int r = i, c = j;
      if (grid[i][j] == 'U') {
        r += 2;
      } else if (grid[i][j] == 'D') {
        r -= 2;
      } else if (grid[i][j] == 'L') {
        c += 2;
      } else {
        c -= 2;
      }

      if (r >= 0 && r < n && c >= 0 && c < m) {
        adj[(i + j) % 2][id[r][c]].push_back(id[i][j]);
      } else {
        roots[(i + j) % 2].push_back(id[i][j]);
      }
    }
  }

  for (auto i : roots[0]) {
    dfs_even(i);
  }

  for (auto i : roots[1]) {
    tree = new segtree();
    dfs_odd(i);
  }

  cout << ans << "\n";
}