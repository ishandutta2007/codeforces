#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
bool visited[N];
int sub[N];

void dfs_sub(int u, int p = -1) {
  sub[u] = 1;
  for (auto c : adj[u]) {
    if (!visited[c] && c != p) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int n, int p = -1) {
  for (auto c : adj[u]) {
    if (!visited[c] && c != p && sub[c] * 2 > n) {
      return dfs_find(c, n, u);
    }
  }
  return u;
}

map<int, int> layers;
int depth[N];
int dist[N];

void dfs_depth(int u, int p = -1) {
  auto it = layers.lower_bound(dist[u] - depth[u]);
  if (it->second < dist[u]) {
    while (it != layers.begin()) {
      auto prv = it;
      if ((--prv)->second > dist[u]) {
        break;
      }
      layers.erase(prv);
    }
    layers[dist[u] - depth[u]] = dist[u];
  }

  for (auto c : adj[u]) {
    if (!visited[c] && c != p) {
      depth[c] = depth[u] + 1;
      dfs_depth(c, u);
    }
  }
}

int ans[N];

void dfs_update(int u, int p = -1) {
  ans[u] = max(ans[u], layers.upper_bound(depth[u])->second);
  for (auto c : adj[u]) {
    if (!visited[c] && c != p) {
      dfs_update(c, u);
    }
  }
}

void solve(int u) {
  dfs_sub(u);
  u = dfs_find(u, sub[u]);
  visited[u] = true;

  layers = {{INT_MAX, 0}};
  depth[u] = 0;
  dfs_depth(u);
  dfs_update(u);

  for (auto c : adj[u]) {
    if (!visited[c]) {
      solve(c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }


  int k;
  cin >> k;
  queue<int> que;
  fill(dist, dist + n, -1);
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    que.push(--a);
    dist[a] = 0;
  }

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto c : adj[u]) {
      if (dist[c] == -1) {
        dist[c] = dist[u] + 1;
        que.push(c);
      }
    }
  }

  solve(0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}