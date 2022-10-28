#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
int par[N], a[N];

void dfs(int u) {
  for (auto c : adj[u]) {
    adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
    par[c] = u;
    dfs(c);
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
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  int u = -1, c = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    while (c == 0) {
      c = adj[a[++u]].size();
    }

    if ((u == -1 && a[i] != 1) || par[a[i]] != a[u]) {
      cout << "No\n";
      exit(0);
    }
    --c;
  }

  cout << "Yes\n";
}