#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  long long lazy, one, two, three;

  void apply(long long value) {
    three += value;
    lazy += value;
    two += value;
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

     if (lazy != 0) {
      left->apply(lazy);
      right->apply(lazy);
      lazy = 0;
    }
  }

  long long calc(long long t, int l, int r) {
    if (l == r) {
      return t - one;
    } else {
      push();
      int m = (l + r) / 2;
      if (t > left->two) {
        return min(t - left->one, right->calc(t, m + 1, r));
      } else {
        return min(left->calc(t, l, m), three);
      }
    }
  }

  void pull(int l, int r) {
    int m = (l + r) / 2;
    one = max(left->one, right->one);
    two = max(left->two, right->two);
    three = right->calc(left->two, m + 1, r);
  }

  void build(int l, int r, long long *x) {
    if (l == r) {
      one = two = three = x[l];
    } else {
      push();
      int m = (l + r) / 2;
      left->build(l, m, x);
      right->build(m + 1, r, x);
      pull(l, r);
    }
  }

  void update(int a, int b, long long x, int l, int r) {
    if (b < l || r < a || a > b) {
      return;
    } else if (a <= l && r <= b) {
      apply(x);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, x, l, m);
      right->update(a, b, x, m + 1, r);
      pull(l, r);
    }
  }

  int find_last(long long k, int l, int r) {
    if (one < k) {
      return -1;
    } else if (l == r) {
      return l;
    } else {
      push();
      int m = (l + r) / 2;
      int res = right->find_last(k, m + 1, r);
      if (res == -1) {
        res = left->find_last(k, l, m);
      }
      return res;
    }
  }

  int query(long long t, long long k, int l, int r) {
    if (l == r) {
      return (t - one <= k) ? l : -1;
    } else {
      push();
      int m = (l + r) / 2, res = -1;
      if (t > left->two) {
        res = right->query(t, k, m + 1, r);
        if (res == -1) {
          res = left->find_last(t - k, l, m);
        }
      } else {
        if (three <= k) {
          res = right->query(left->two, k, m + 1, r);
        } else {
          res = left->query(t, k, l, m);
        }
      }
      return res;
    }
  }

};

const long long A = 1000000000LL * 1000000000LL;
const int N = 100000;

vector<int> adj[N], path;
long long prefix[2][N];
segtree *kekoland;
int ans, n, k;

void dfs(int u) {
  int lo = -1, hi = path.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (prefix[0][u] - prefix[0][path[mid]] <= k) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  int v = (lo == -1) ? n : path[lo];

  kekoland->update(0, u - 1, -A, 0, n - 1);
  kekoland->update(v, n - 1, A, 0, n - 1);
  ans = max(ans, kekoland->query(-A, k, 0, n - 1) - u + 1);
  kekoland->update(v, n - 1, -A, 0, n - 1);
  kekoland->update(0, u - 1, A, 0, n - 1);

  for (auto c : adj[u]) {
    long long offset = prefix[0][c] - prefix[0][u];
    kekoland->update(u - 1, n - 1, offset, 0, n - 1);
    path.push_back(u);
    dfs(c);
    path.pop_back();
    kekoland->update(u - 1, n - 1, -offset, 0, n - 1);
  }
}

int g[N], w[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n - 1; ++i) {
    cin >> w[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }

  prefix[1][0] = g[0];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      prefix[i][j + 1] = prefix[i][j] + g[i + j] - w[j];
    }
  }

  vector<int> stk, roots;
  for (int i = n - 1; i >= 0; --i) {
    while (!stk.empty() && prefix[0][stk.back()] >= prefix[0][i]) {
      stk.pop_back();
    }

    if (!stk.empty()) {
      adj[stk.back()].push_back(i);
    } else {
      roots.push_back(i);
    }

    stk.push_back(i);
  }

  kekoland = new segtree();
  kekoland->build(0, n - 1, prefix[1]);

  for (auto i : roots) {
    dfs(i);
  }

  cout << ans << "\n";
}