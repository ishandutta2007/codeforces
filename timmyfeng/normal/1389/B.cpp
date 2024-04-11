#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int Z = 6;

struct state {
  int i, z, b, k;
};

int dp[N][Z][2];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k, z;
    cin >> n >> k >> z;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= z; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = 0;
        }
      }
    }

    queue<state> que;
    dp[0][0][0] = a[0];
    que.push({0, 0, 0, 0});

    int ans = 0;
    while (!que.empty()) {
      state u = que.front();
      que.pop();

      int val = dp[u.i][u.z][u.b];

      if (u.k == k) {
        ans = max(ans, val);
        continue;
      } else {
        if (u.i > 0 && u.z < z && !u.b && val + a[u.i - 1] > dp[u.i - 1][u.z + 1][1]) {
          dp[u.i - 1][u.z + 1][1] = val + a[u.i - 1];
          que.push({u.i - 1, u.z + 1, 1, u.k + 1});
        }

        if (u.i < n - 1 && val + a[u.i + 1] > dp[u.i + 1][u.z][0]) {
          dp[u.i + 1][u.z][0] = val + a[u.i + 1];
          que.push({u.i + 1, u.z, 0, u.k + 1});
        }
      }
    }

    cout << ans << "\n";
  }
}