#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

vector<int> adj[N], order;
bool visited[N];

void dfs_order(int u) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs_order(c);
    }
  }
  order.push_back(u);
}

vector<int> jda[N];
bool source[N];
int color[N];

void dfs_color(int u, int x) {
  color[u] = x;
  for (auto c : jda[u]) {
    if (color[c] == -1) {
      dfs_color(c, x);
    }
    if (color[c] != x) {
      source[color[c]] = true;
    }
  }
}

int edges[N][2], cycle[N], dist[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i][0] = --u;
    edges[i][1] = --v;
    adj[u].push_back(v);
    jda[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs_order(i);
    }
  }

  int k = 0;
  fill(color, color + n, -1);
  while (!order.empty()) {
    int u = order.back();
    order.pop_back();
    if (color[u] == -1) {
      dfs_color(u, k++);
    }
  }

  fill(cycle, cycle + k, INT_MAX);
  for (int i = 0; i < m; ++i) {
    int u = edges[i][0], v = edges[i][1];
    if (color[u] == color[v] && !source[color[u]]) {
      fill(dist, dist + n, -1);
      queue<int> que;
      que.push(v);
      dist[v] = 0;
      while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (auto y : adj[x]) {
          if (dist[y] == -1) {
            dist[y] = dist[x] + 1;
            que.push(y);
          }
        }
      }
      cycle[color[u]] = min(cycle[color[u]], dist[u] + 1);
    }
  }

  int ans = n;
  for (int i = 0; i < k; ++i) {
    if (!source[i] && cycle[i] < INT_MAX) {
      ans += 998 * cycle[i] + 1;
    }
  }

  cout << ans << "\n";
}