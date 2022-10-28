#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];

array<int, 2> dfs(int u, int p = -1) {
  int maxi = 1;
  int leaf = INT_MAX;
  vector<int> children;
  for (auto c : adj[u]) {
    if (c != p) {
      auto [maxi_c, leaf_c] = dfs(c, u);
      children.push_back(leaf_c + 1);
      leaf = min(leaf, leaf_c + 1);
      maxi = max(maxi, maxi_c);
    }
  }
  sort(children.begin(), children.end());

  if (!children.empty()) {
    for (int i = 0; i < (int) children.size() - (p == -1); ++i) {
      maxi = max(maxi, children[i] + 1);
    }
    maxi = max(maxi, children.back());
  } else {
    leaf = 0;
  }

  return {maxi, leaf};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    fill(adj, adj + n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout << dfs(0)[0] << "\n";
  }
}