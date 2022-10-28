#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

vector<pair<int, int>> adj[N];
bool special[N];
int weight[N];
int value[N];

vector<pair<int, int>> bcc[N];
int cnt_bcc, timer, k;
bool visited[N];
int time_in[N];
int color[N];
int low[N];

long long ans[N];
long long dp[N];
int cnt[N];

void dfs_color(int u, int p) {
  cnt[cnt_bcc] += special[u];
  dp[cnt_bcc] += value[u];
  color[u] = cnt_bcc;
  for (auto [c, w] : adj[u]) {
    if (c != p && color[c] == 0) {
      dfs_color(c, u);
    }
  }
}

void dfs_bcc(int u, int p) {
  time_in[u] = ++timer;
  low[u] = time_in[u];
  visited[u] = true;

  for (auto [c, w] : adj[u]) {
    if (c != p) {
      if (visited[c]) {
        low[u] = min(low[u], time_in[c]);
      } else {
        dfs_bcc(c, u);
        low[u] = min(low[u], low[c]);
        if (low[c] > time_in[u]) {
          ++cnt_bcc;
          dfs_color(c, u);
        }
      }
    }
  }
}

void update(int u, int c, int w, int type) {
  cnt[u] += cnt[c] * type;
  if (cnt[c] == k || cnt[c] == 0) {
    dp[u] += dp[c] * type;
  } else {
    dp[u] += max(0LL, dp[c] - w) * type;
  }
}

void dfs_pull(int u, int p) {
  for (auto [c, w] : bcc[u]) {
    if (c != p) {
      dfs_pull(c, u);
      update(u, c, w, 1);
    }
  }
}

void dfs_push(int u, int p) {
  ans[u] = dp[u];
  for (auto [c, w] : bcc[u]) {
    if (c != p) {
      update(u, c, w, -1);
      update(c, u, w, 1);
      dfs_push(c, u);
      update(c, u, w, -1);
      update(u, c, w, 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> k;

  for (int i = 0; i < k; ++i) {
    int v;
    cin >> v;
    special[v] = true;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> value[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> weight[i];
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v, weight[i]);
    adj[v].emplace_back(u, weight[i]);
  }

  dfs_bcc(1, 0);
  ++cnt_bcc;
  dfs_color(1, 0);

  for (int u = 1; u <= n; ++u) {
    for (auto [v, w] : adj[u]) {
      if (color[u] != color[v]) {
        bcc[color[u]].emplace_back(color[v], w);
      }
    }
  }

  dfs_pull(1, 0);
  dfs_push(1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << ans[color[i]] << " ";
  }
  cout << "\n";
}