#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

set<int> adj[N];
int u[N], v[N];
bool dead[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
    adj[u[i]].insert(v[i]);
    adj[v[i]].insert(u[i]);
  }

  multiset<array<int, 2>> nodes;
  for (int i = 0; i < n; ++i) {
    if (!adj[i].empty()) {
      nodes.insert({(int) adj[i].size(), i});
    }
  }

  for (int i = m - 1; i >= 0; --i) {
    while (!nodes.empty() && (*nodes.begin())[0] < k) {
      int x = (*nodes.begin())[1];
      dead[x] = true;
      for (auto y : adj[x]) {
        nodes.erase({(int) adj[y].size(), y});
        adj[y].erase(x);
        nodes.insert({(int) adj[y].size(), y});
      }
      nodes.erase({(int) adj[x].size(), x});
      adj[x].clear();
    }

    ans[i] = nodes.size();

    if (!dead[u[i]] && !dead[v[i]]) {
      for (int j = 0; j < 2; ++j) {
        nodes.erase({(int) adj[u[i]].size(), u[i]});
        adj[u[i]].erase(v[i]);
        nodes.insert({(int) adj[u[i]].size(), u[i]});
        swap(u[i], v[i]);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << "\n";
  }
}