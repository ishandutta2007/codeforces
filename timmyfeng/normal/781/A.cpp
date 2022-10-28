#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
int color[N];

void dfs(int u, int p) {
  int nxt = 1;
  for (auto c : adj[u]) {
    if (c != p) {
      while (nxt == color[u] || (p != -1 && nxt == color[p])) {
        ++nxt;
      }
      color[c] = nxt++;
      dfs(c, u);
    }
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
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }


  color[0] = 1;
  dfs(0, -1);

  cout << *max_element(color, color + n) << "\n";
  for (int i = 0; i < n; ++i) {
    cout << color[i] << " ";
  }
  cout << "\n";
}