#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int dep[N];
int par[N];
int k;

void dfs_dep(int u, int p) {
  for (int c : adj[u]) {
    if (c != p) {
      dep[c] = dep[u] + 1;
      par[c] = u;
      dfs_dep(c, u);
    }
  }
}

void dfs_check(int u, int p) {
  if (dep[u] < k && int(adj[u].size()) + !p < 4) {
    cout << "No\n";
    exit(0);
  }
  if (dep[u] >= k && int(adj[u].size()) > 1) {
    cout << "No\n";
    exit(0);
  }

  for (int c : adj[u]) {
    if (c != p) {
      dfs_check(c, u);
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

  dfs_dep(1, 0);
  int root = max_element(dep, dep + n + 1) - dep;
  dep[root] = 0;
  dfs_dep(root, 0);
  root = max_element(dep, dep + n + 1) - dep;

  int len = dep[root];
  for (int i = 0; i < len / 2; ++i) {
    root = par[root];
  }

  if (len != 2 * k) {
    cout << "No\n";
    exit(0);
  }

  dep[root] = 0;
  dfs_dep(root, 0);
  dfs_check(root, 0);
  cout << "Yes\n";
}