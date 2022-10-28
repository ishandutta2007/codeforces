#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

bool visited[N][2];
vector<int> adj[N];
vector<int> path;
int color[N];

void dfs(int u, int color) {
  visited[u][color] = true;

  if (adj[u].empty() && color == 1) {
    cout << "Win\n";
    for (int v : path) {
      cout << v << " ";
    }
    cout << u << "\n";
    exit(0);
  }

  path.push_back(u);
  for (int c : adj[u]) {
    if (!visited[c][color ^ 1]) {
      dfs(c, color ^ 1);
    }
  }
  path.pop_back();
}

void dfs_draw(int u) {
  color[u] = 1;
  for (int c : adj[u]) {
    if (color[c] == 0) {
      dfs_draw(c);
    } else if (color[c] == 1) {
      cout << "Draw\n";
      exit(0);
    }
  }
  color[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int v;
      cin >> v;
      adj[i].push_back(v);
    }
  }

  int s;
  cin >> s;
  dfs(s, 0);
  dfs_draw(s);

  cout << "Lose\n";
}