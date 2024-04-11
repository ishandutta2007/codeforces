#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

set<int> ice_cream[N];
vector<int> adj[N];

priority_queue<int, vector<int>, greater<int>> indices;
bool in_indices[N];

int ans[N];

void dfs(int u, int p) {
  vector<int> todo1;
  for (auto i : ice_cream[u]) {
    if (p == -1 || ice_cream[p].count(i) == 0) {
      while (!in_indices[indices.top()]) {
        indices.pop();
      }

      ans[i] = indices.top();
      in_indices[ans[i]] = false;
      todo1.push_back(ans[i]);
      indices.pop();
    }
  }

  for (auto c : adj[u]) {
    if (c != p) {
      vector<int> todo2;
      for (auto i : ice_cream[u]) {
        if (ice_cream[c].count(i) == 0) {
          indices.push(ans[i]);
          in_indices[ans[i]] = true;
          todo2.push_back(ans[i]);
        }
      }

      dfs(c, u);

      for (auto i : todo2) {
        in_indices[i] = false;
      }
    }
  }

  for (auto i : todo1) {
    indices.push(i);
    in_indices[i] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    while (s--) {
      int a;
      cin >> a;
      ice_cream[i].insert(a - 1);
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < m; ++i) {
    indices.push(i);
    in_indices[i] = true;
  }

  dfs(0, -1);

  cout << *max_element(ans, ans + m) + 1 << "\n";
  for (int i = 0; i < m; ++i) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}