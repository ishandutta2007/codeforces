#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int O = 512;

vector<int> adj[N];
vector<int> order;
int dp[N];

void dfs_sort(int u) {
  for (int c : adj[u]) {
    adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
    dfs_sort(c);
  }
  order.push_back(u);
}

int solve(int k) {
  int res = 0;
  for (int u : order) {
    dp[u] = 1;
    int oth = 0;
    for (int c : adj[u]) {
      if (dp[c] + 1 > dp[u]) {
        oth = dp[u] - 1;
        dp[u] = dp[c] + 1;
      } else if (dp[c] > oth) {
        oth = dp[c];
      }
    }

    if (dp[u] + oth >= k) {
      dp[u] = 0;
      ++res;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_sort(1);

  int ptr = 1;
  int cur = n;
  for ( ; ptr <= min(n, O); ++ptr) {
    cout << cur << "\n";
    cur = solve(ptr + 1);
  }

  while (ptr <= n) {
    int nxt = -1;
    int lo = ptr + 1;
    int hi = n;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int res = solve(mid);
      if (res != cur) {
        nxt = res;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    while (ptr < lo) {
      cout << cur << "\n";
      ++ptr;
    }
    cur = nxt;
  }
}