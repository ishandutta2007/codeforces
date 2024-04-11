#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

vector<int> adj[N];
int color[N];

void dfs(int u) {
  for (auto c : adj[u]) {
    if (color[c] == 0) {
      color[c] = 3 - color[u];
      dfs(c);
    }
    if (color[c] + color[u] != 3) {
      cout << -1 << "\n";
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0) {
      color[i] = 1;
      dfs(i);
    }
  }

  for (int i = 1; i <= 2; ++i) {
    cout << count(color + 1, color + n + 1, i) << "\n";
    for (int j = 1; j <= n; ++j) {
      if (color[j] == i) {
        cout << j << " ";
      }
    }
    cout << "\n";
  }
}