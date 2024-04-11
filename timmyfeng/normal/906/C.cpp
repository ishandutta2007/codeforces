#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int pre_node[1 << N];
int pre_mask[1 << N];
int dp[1 << N];
int reach[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    reach[u] |= 1 << v;
    reach[v] |= 1 << u;
  }

  fill(dp, dp + (1 << n), n + 1);
  for (int i = 0; i < (1 << n); ++i) {
    int mask = (1 << n) - 1;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) > 0) {
        mask &= reach[j] ^ (1 << j);
      }
    }

    if ((mask & i) == i) {
      dp[i] = 0;
    }

    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) > 0) {
        int i_new = i | reach[j];
        if (dp[i] + 1 < dp[i_new]) {
          dp[i_new] = dp[i] + 1;
          pre_node[i_new] = j;
          pre_mask[i_new] = i;
        }
      }
    }
  }

  int mask = (1 << n) - 1;
  cout << dp[mask] << "\n";
  while (dp[mask] != 0) {
    cout << pre_node[mask] + 1 << " ";
    mask = pre_mask[mask];
  }
  cout << "\n";
}