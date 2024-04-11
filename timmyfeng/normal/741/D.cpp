#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
const int A = 22;

vector<array<int, 2>> adj[N];
int sub[N];

void dfs_sub(int u) {
  sub[u] = 1;
  for (auto [c, w] : adj[u]) {
    dfs_sub(c);
    sub[u] += sub[c];
  }

  for (auto &e : adj[u]) {
    if (sub[e[0]] > sub[adj[u].back()[0]]) {
      swap(e, adj[u].back());
    }
  }
}

int max_length[1 << A];
int value;
int key;

int dfs_update(int u, int path, int depth) {
  int res = max_length[path ^ key] + value + depth;
  for (int i = 0; i < A; ++i) {
    res = max(res, max_length[path ^ key ^ (1 << i)] + value + depth);
  }

  for (auto [c, w] : adj[u]) {
    res = max(res, dfs_update(c, path ^ (1 << w), depth + 1));
  }
  return res;
}

void dfs_insert(int u, int path, int depth) {
  max_length[path ^ key] = max(max_length[path ^ key], depth - value);
  for (auto [c, w] : adj[u]) {
    dfs_insert(c, path ^ (1 << w), depth + 1);
  }
}

void dfs_erase(int u, int path) {
  max_length[path ^ key] = INT_MIN;
  for (auto [c, w] : adj[u]) {
    dfs_erase(c, path ^ (1 << w));
  }
}

int ans[N];

void dfs_dsu(int u) {
  for (auto [c, w] : adj[u]) {
    dfs_dsu(c);
    ans[u] = max(ans[u], ans[c]);
    if (c != adj[u].back()[0]) {
      dfs_erase(c, 0);
    } else {
      key ^= 1 << w;
      ++value;
    }
  }

  max_length[key] = max(max_length[key], -value);
  for (auto [c, w] : adj[u]) {
    if (c != adj[u].back()[0]) {
      ans[u] = max(ans[u], dfs_update(c, 1 << w, 1));
      dfs_insert(c, 1 << w, 1);
    }
  }

  ans[u] = max(ans[u], max_length[key] + value);
  for (int i = 0; i < A; ++i) {
    ans[u] = max(ans[u], max_length[key ^ (1 << i)] + value);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int p;
    char c;
    cin >> p >> c;
    adj[p - 1].push_back({i, c - 'a'});
  }

  fill(max_length, max_length + (1 << A), INT_MIN);

  dfs_sub(0);
  dfs_dsu(0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}