#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
bool uni[N];
int sub[N];

void dfs_sub(int u, int p = -1) {
  sub[u] = uni[u];
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int k, int p = -1) {
  for (auto c : adj[u]) {
    if (c != p && sub[c] > k) {
      return dfs_find(c, k, u);
    }
  }
  return u;
}

long long dfs_sum(int u, int d, int p = -1) {
  long long sum = uni[u] ? d : 0;
  for (auto c : adj[u]) {
    if (c != p) {
      sum += dfs_sum(c, d + 1, u);
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < 2 * k; ++i) {
    int a;
    cin >> a;
    uni[a - 1] = true;
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_sub(0);

  cout << dfs_sum(dfs_find(0, k), 0) << "\n";
}