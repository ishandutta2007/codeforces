#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

constexpr int kInf = 1'000'000'000;

struct Node {
  int dp[4][3][2];

  Node(char c) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = kInf;
        }
      }
    }
    if (c == 'a') {
      dp[1][0][0] = 0;
      dp[0][0][0] = 1;
    } else if (c == 'b') {
      dp[0][1][0] = 0;
      dp[0][0][0] = 1;
    } else {
      dp[0][0][1] = 0;
      dp[0][0][0] = 1;
    }
  }

  Node() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = kInf;
        }
      }
    }
  }
};

Node Merge(const Node& lhs, const Node& rhs) {
  Node result;
  int A[4], B[4];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (lhs.dp[i][j][k] == kInf) continue;
        for (int x = 0; x < 4; ++x) {
          for (int y = 0; y < 3; ++y) {
            for (int z = 0; z < 2; ++z) {
              if (rhs.dp[x][y][z] == kInf) continue;
              A[0] = i;
              A[1] = j;
              A[2] = k;
              A[3] = 0;
              B[0] = x;
              B[1] = y;
              B[2] = z;
              B[3] = 0;
              result.dp[A[0] + B[A[0]]][A[1] + B[1 + A[1]]][A[2] + B[2 + A[2]]] =
                  min(result.dp[A[0] + B[A[0]]][A[1] + B[1 + A[1]]][A[2] + B[2 + A[2]]],
                      lhs.dp[i][j][k] + rhs.dp[x][y][z]);
            }
          }
        }
      }
    }
  }
  // for (int i = 0; i < 4; ++i) {
  //   for (int j = 0; j < 3; ++j) {
  //     for (int k = 0; k < 2; ++k) {
  //       cout << "dp[" << i << "][" << j << "][" << k << "] = " << result.dp[i][j][k] << endl;
  //     }
  //   }
  // }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;

  vector<Node> tree(N * 4);

  auto Build = [&]() {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        tree[o] = Node(s[l]);
        return;
      }
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    return dfs(dfs, 0, N);
  };

  Build();

  auto Update = [&](int p, char c) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        tree[o] = Node(c);
        return;
      }
      int m = (l + r) >> 1;
      if (p < m) dfs(dfs, l, m, o * 2 + 1);
      else dfs(dfs, m, r, o * 2 + 2);
      tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    return dfs(dfs, 0, N);
  };

  while (Q--) {
    int pos;
    string t;
    cin >> pos >> t;
    pos--;
    Update(pos, t[0]);
    int ans = kInf;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 2; ++k) {
          ans = min(ans, tree[0].dp[i][j][k]);
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}