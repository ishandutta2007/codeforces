#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<int> adj[N];
bool x[N];
bool y[N];

int dfs(int u, int p) {
  if (x[u])
    return u;
  int res = 0;
  for (int c : adj[u]) {
    if (c != p) {
      res ^= dfs(c, u);
    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  fill(adj, adj + n + 1, vector<int>());
  memset(x, false, sizeof x);
  memset(y, false, sizeof y);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int k1, u;
  cin >> k1;
  for (int i = 0; i < k1; ++i) {
    cin >> u;
    x[u] = true;
  }

  int k2;
  cin >> k2;
  for (int i = 0; i < k2; ++i) {
    cin >> u;
    y[u] = true;
  }

  cout << "B " << u << endl;
  cin >> u;

  int v;
  u = dfs(u, 0);
  cout << "A " << u << endl;
  cin >> v;

  if (y[v]) {
    cout << "C " << u << endl;
  } else {
    cout << "C " << -1 << endl;
  }
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