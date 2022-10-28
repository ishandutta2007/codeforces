#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
vector<int> bcc;
vector<int> stk;
bool visited[N];
int color[N];

void dfs_bcc(int u, int p = -1) {
  color[u] = 1;
  stk.push_back(u);
  for (auto c : adj[u]) {
    if (c != p) {
      if (color[c] == 1) {
        bcc = vector<int>(find(stk.begin(), stk.end(), c), stk.end());
      } else if (color[c] == 0) {
        dfs_bcc(c, u);
      }
    }
  }
  stk.pop_back();
  color[u] = 2;
}

int dfs_sub(int u) {
  int sub = 1;
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      sub += dfs_sub(c);
    }
  }
  return sub;
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
    fill(visited, visited + n, false);
    fill(color, color + n, 0);

    for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs_bcc(0);
    for (auto i : bcc) {
      visited[i] = true;
    }

    long long ans = (long long) n * (n - 1);
    for (auto i : bcc) {
      int sub = dfs_sub(i);
      ans -= (long long) sub * (sub - 1) / 2;
    }

    cout << ans << "\n";
  }
}