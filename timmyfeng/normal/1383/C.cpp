#include <bits/stdc++.h>
using namespace std;

const int A = 20;

int reach[A];
bool dp[1 << A];
bool visited[A];

bool dfs(int u) {
  if (visited[u])
    return false;
  visited[u] = true;
  for (int v = 0; v < A; ++v) {
    if ((reach[u] & (1 << v)) > 0 || (reach[v] & (1 << u))) {
      dfs(v);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    memset(reach, 0, sizeof reach);
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        reach[a[i] - 'a'] |= 1 << (b[i] - 'a');
      }
    }

    memset(dp, false, sizeof dp);
    dp[0] = true;
    int dag = 0;

    for (int mask = 1; mask < (1 << A); ++mask) {
      for (int i = 0; i < A; ++i) {
        if ((mask & (1 << i)) > 0) {
          dp[mask] |= (dp[mask ^ (1 << i)] && (mask & reach[i]) == 0);
        }
      }
      if (dp[mask]) {
        dag = max(dag, __builtin_popcount(mask));
      }
    }

    int cnt = 0;
    memset(visited, false, sizeof visited);
    for (int i = 0; i < A; ++i) {
      cnt += dfs(i);
    }

    cout << 2 * A - dag - cnt << "\n";
  }
}