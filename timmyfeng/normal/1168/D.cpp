#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e5 + 1;
const int A = 26;

vector<int> adj[N];
int height[N];
int node[N];
int par[N];

char color[N];
int cnt[N][A];
int mx[N][A];
bool ok[N];

int m;

void dfs_height(int u) {
  height[u] = 0;
  for (int c : adj[u]) {
    dfs_height(c);
    if (height[u] == 0) {
      height[u] = height[c] + 1;
    } else if (height[u] != height[c] + 1) {
      for (int i = 0; i < m; ++i) {
        cout << "Fou\n";
      }
      exit(0);
    }
  }
}

void pull(int u) {
  ok[u] = true;
  fill(mx[u], mx[u] + A, 0);
  for (int c : adj[u]) {
    ok[u] &= ok[c];
    for (int i = 0; i < A; ++i) {
      mx[u][i] = max(mx[u][i], mx[c][i]);
    }
  }
  ok[u] &= (accumulate(mx[u], mx[u] + A, 0) <= height[u]);

  for (int i = 0; i < A; ++i) {
    mx[u][i] += cnt[u][i];
  }
}

int dfs(int u) {
  vector<int> path;
  while (adj[u].size() == 1u) {
    path.push_back(u);
    u = adj[u][0];
  }

  node[u] = u;
  for (auto v : path) {
    node[v] = u;
    for (int i = 0; i < A; ++i) {
      cnt[u][i] += cnt[v][i];
    }
  }

  for (auto& c : adj[u]) {
    c = dfs(c);
    par[c] = u;
  }
  pull(u);
  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> m;

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p >> color[i];
    adj[p].push_back(i);
    if (color[i] >= 'a') {
      ++cnt[i][color[i] - 'a'];
    }
  }

  dfs_height(1);
  int root = dfs(1);

  while (m--) {
    int u;
    cin >> u;
    if (color[u] >= 'a') {
      --cnt[node[u]][color[u] - 'a'];
    }

    cin >> color[u];
    if (color[u] >= 'a') {
      ++cnt[node[u]][color[u] - 'a'];
    }

    u = node[u];
    while (u != 0) {
      pull(u);
      u = par[u];
    }

    if (ok[root]) {
      int sum = (height[1] - accumulate(mx[root], mx[root] + A, 0)) * 13 * 27;
      for (int i = 0; i < A; ++i) {
        sum += mx[root][i] * (i + 1);
      }
      cout << "Shi " << sum << "\n";
    } else {
      cout << "Fou\n";
    }
  }
}