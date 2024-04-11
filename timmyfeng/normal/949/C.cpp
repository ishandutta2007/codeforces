#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

vector<int> nodes[N];
vector<int> adj[N];
vector<int> jda[N];
vector<int> order;
bool visited[N];
bool leaf[N];
int color[N];
int hour[N];

void dfs_order(int u) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs_order(c);
    }
  }
  order.push_back(u);
}

void dfs_color(int u, int cur) {
  color[u] = cur;
  nodes[cur].push_back(u);
  for (auto c : jda[u]) {
    if (color[c] == -1) {
      dfs_color(c, cur);
    } else if (color[c] != cur) {
      leaf[color[c]] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, h;
  cin >> n >> m >> h;

  for (int i = 0; i < n; ++i) {
    cin >> hour[i];
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if ((hour[u] + 1) % h == hour[v]) {
      adj[u].push_back(v);
      jda[v].push_back(u);
    }
    if ((hour[v] + 1) % h == hour[u]) {
      adj[v].push_back(u);
      jda[u].push_back(v);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs_order(i);
    }
  }

  int cur = 0;
  fill(color, color + n, -1);
  while (!order.empty()) {
    int u = order.back();
    order.pop_back();

    if (color[u] == -1) {
      leaf[cur] = true;
      dfs_color(u, cur);
      ++cur;
    }
  }

  vector<int> ans;
  bool ok = false;
  for (int i = 0; i < cur; ++i) {
    if (leaf[i]) {
      if (!ok || nodes[i].size() < ans.size()) {
        ans = nodes[i];
        ok = true;
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}