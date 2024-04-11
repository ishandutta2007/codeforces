#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;

vector<int> adj[N];
bool visited[N];
int sum[N];
int w[N];
int b[N];

vector<int> todo;

array<int, 2> dfs(int u) {
  array<int, 2> sub = {w[u], b[u]};
  todo.push_back(u);
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      array<int, 2> child = dfs(c);
      for (int i = 0; i < 2; ++i) {
        sub[i] += child[i];
      }
    }
  }
  return sub;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  fill(sum + 1, sum + k + 1, INT_MIN);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      auto [sum_w, sum_b] = dfs(i);
      for (int j = k; j > 0; --j) {
        if (j >= sum_w) {
          sum[j] = max(sum[j], sum[j - sum_w] + sum_b);
        }
        for (auto u : todo) {
          if (j >= w[u]) {
            sum[j] = max(sum[j], sum[j - w[u]] + b[u]);
          }
        }
      }
      todo.clear();
    }
  }

  cout << *max_element(sum, sum + k + 1) << "\n";
}