#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> euler_path;

vector<int> adj[N];
bool visited[N];

void dfs(int u) {
  visited[u] = true;
  euler_path.push_back(u);
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs(c);
      euler_path.push_back(u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l;
  cin >> n >> m >> l;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0);

  for (int i = 0, k = 0; i < l; ++i) {
    vector<int> ans;
    for (int j = 0; j < (2 * n - 1) / l + 1 && k < (int) euler_path.size(); ++j) {
      ans.push_back(euler_path[k]);
      ++k;
    }

    if (ans.empty()) {
      ans.push_back(0);
    }

    cout << ans.size() << " ";
    for (auto j : ans) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}