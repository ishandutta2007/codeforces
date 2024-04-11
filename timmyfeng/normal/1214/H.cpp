#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<int> adj[N];
int height[N][3];
int color[N];
int dist[N];
int par[N];
int dep, k;

void update(int u, int c) {
  if (c == 0)
    return;
  for (int i = 0; i < 3; ++i) {
    if (height[c][0] + 1 > height[u][i]) {
      for (int j = 2; j > i; --j) {
        height[u][j] = height[u][j - 1];
      }
      height[u][i] = height[c][0] + 1;
      return;
    }
  }
}

void dfs_pull(int u, int p) {
  for (int c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      update(u, c);
    }
  }
}

void dfs_push(int u, int p) {
  update(u, p);
  if (height[u][0] + height[u][1] >= k - 1 && height[u][1] + height[u][2] >= k - 1 && height[u][2] > 0) {
    cout << "No\n";
    exit(0);
  }

  for (int c : adj[u]) {
    if (c != p) {
      int pre2 = height[u][0];
      if (height[u][0] == height[c][0] + 1) {
        height[u][0] = height[u][1];
      }
      dfs_push(c, u);
      height[u][0] = pre2;
    }
  }
}

pair<int, int> dfs_dep(int u, int dep) {
  pair<int, int> far = {dep, u};
  for (int c : adj[u]) {
    if (c != par[u]) {
      par[c] = u;
      far = max(far, dfs_dep(c, dep + 1));
    }
  }
  return far;
}

void dfs_color(int u, int p, int cur, int dir) {
  cur = (cur + dir + k) % k;
  color[u] = cur;
  for (int c : adj[u]) {
    if (c != p) {
      dfs_color(c, u, cur, dir);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (k > 2) {
    dfs_pull(1, 0);
    dfs_push(1, 0);
  }

  int root = dfs_dep(1, 0).second;
  par[root] = 0;
  auto [diameter, u] = dfs_dep(root, 0);

  int cur = 0;
  int pre = 0;
  while (u != root) {
    color[u] = cur % k;
    for (int c : adj[u]) {
      if (c != par[u] && c != pre) {
        dfs_color(c, u, cur, (2 * cur > diameter ? 1 : -1));
      }
    }
    pre = u;
    u = par[u];
    ++cur;
  }

  color[root] = cur % k;

  cout << "Yes\n";
  for (int i = 1; i <= n; ++i) {
    cout << color[i] + 1 << " ";
  }
  cout << "\n";
}