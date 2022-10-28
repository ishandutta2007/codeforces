#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int dist[N];

void dfs(int u, int p) {
  for (auto c : adj[u]) {
    if (c != p) {
      dist[c] = dist[u] + 1;
      dfs(c, u);
    }
  }
}

void solve() {
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;

  fill(adj, adj + n + 1, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dist[a] = 0;
  dfs(a, 0);

  if (dist[b] <= da) {
    cout << "Alice\n";
    return;
  }

  int root = max_element(dist, dist + n + 1) - dist;
  dist[root] = 0;
  dfs(root, 0);

  db = min(db, *max_element(dist, dist + n + 1));
  cout << (da * 2 >= db ? "Alice" : "Bob") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}