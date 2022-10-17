#include <bits/stdc++.h>
using namespace std;

constexpr double kEps = 1e-9;
int x, y;
vector<double> kV;

struct Node {
  double dp[4][4];

  Node() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        dp[i][j] = -1e100;
      }
    }
  }

  Node(int v) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        dp[i][j] = -1e100;
      }
    }
    for (int i = 0; i < 4; ++i) {
      if (x * kV[i] < 1 + kEps && y * kV[i] < 1 + kEps) {
        dp[i][i] = v * kV[i];
      }
    }
  }
  Node operator+(const Node& rhs) const {
    Node res;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
          for (int l = 0; l < 4; ++l) {
            if (x * kV[j] + y * kV[k] < 1 + kEps &&
                y * kV[j] + x * kV[k] < 1 + kEps) {
              res.dp[i][l] = max(res.dp[i][l], dp[i][j] + rhs.dp[k][l]);
            }
          }
        }
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  cin >> x >> y;
  vector<int> b(N);
  for (int i = 0; i < N; ++i) {
    cin >> b[i];
  }
  kV = {static_cast<double>(1) / x, static_cast<double>(1) / y,
        static_cast<double>(0), static_cast<double>(1) / (x + y)};

  vector<Node> tree(N * 4);

  auto Build = [&]() {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) {
      if (r - l == 1) {
        tree[o] = Node(b[l]);
        return;
      }
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = tree[o * 2 + 1] + tree[o * 2 + 2];
    };

    return dfs(dfs, 0, N);
  };

  Build();

  auto Update = [&](int p, int v) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        tree[o] = Node(v);
        return;
      }
      int m = (l + r) >> 1;
      if (p < m) {
        dfs(dfs, l, m, o * 2 + 1);
      } else {
        dfs(dfs, m, r, o * 2 + 2);
      }
      tree[o] = tree[o * 2 + 1] + tree[o * 2 + 2];
    };

    return dfs(dfs, 0, N);
  };

  auto Query = [&](int ql, int qr) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> Node {
      if (l >= ql && r <= qr) {
        return tree[o];
      }
      int m = (l + r) >> 1;
      if (qr <= m) {
        return dfs(dfs, l, m, o * 2 + 1);
      } else if (ql >= m) {
        return dfs(dfs, m, r, o * 2 + 2);
      } else {
        return dfs(dfs, l, m, o * 2 + 1) + dfs(dfs, m, r, o * 2 + 2);
      }
    };

    return dfs(dfs, 0, N);
  };

  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, v;
      cin >> k >> v;
      Update(k - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      Node res = Query(l - 1, r);
      double ans = 0;
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          ans = max(ans, res.dp[i][j]);
        }
      }
      cout << fixed << setprecision(20) << ans << "\n";
    }
  }
}