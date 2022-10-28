#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int mad[N];
int cnt[N];
int pp[N];
int h[N];
bool ok;

void dfs(int u, int p) {
  cnt[u] = pp[u];
  for (int c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      cnt[u] += cnt[c];
    }
  }

  ok &= (cnt[u] >= h[u] && (cnt[u] - h[u]) % 2 == 0 && abs(h[u]) <= cnt[u]);
  mad[u] = (cnt[u] - h[u]) / 2;

  int sub = 0;
  for (int c : adj[u]) {
    if (c != p) {
      sub += mad[c];
    }
  }
  ok &= sub >= mad[u] - pp[u];
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> pp[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  fill(adj, adj + 1 + n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ok = true;
  dfs(1, 0);

  cout << (ok ? "YES" : "NO") << "\n";
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