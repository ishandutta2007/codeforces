#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

vector<array<int, 2>> tree[N];
vector<int> adj[N];
int sub[N], ans[N];

void dfs(int u) {
  sub[u] = 1;
  for (auto c : adj[u]) {
    dfs(c);
    if (tree[u].empty() || tree[c].back() > tree[u].back()) {
      swap(tree[c], tree[u]);
    }
    sub[u] += sub[c];
  }
  tree[u].push_back({sub[u], u});
  ans[u] = (*lower_bound(tree[u].begin(), tree[u].end(), array<int, 2>{sub[u] / 2 + 1, 0}))[1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }

  dfs(0);

  while (m--) {
    int u;
    cin >> u;
    cout << ans[u - 1] + 1 << "\n";
  }
}