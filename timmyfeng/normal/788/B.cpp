#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;

vector<int> adj[N];
bool important[N];
bool visited[N];
int degree[N];

void dfs(int u) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs(c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int loops = 0;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    important[u] = true;
    important[v] = true;

    if (u == v) {
      ++loops;
    } else {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  int root = 0;
  while (!important[root]) {
    ++root;
  }
  dfs(root);

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && important[i]) {
      cout << 0 << "\n";
      exit(0);
    }
  }

  long long ans = (long long) loops * (loops - 1) / 2;
  for (int i = 0; i < n; ++i) {
    int degree = adj[i].size();
    ans += (long long) degree * (degree - 1) / 2;
  }
  ans += (long long) loops * (m - loops);

  cout << ans << "\n";
}