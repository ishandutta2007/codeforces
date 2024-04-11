#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> adj[N];

vector<int> branches[N];
vector<int> path;
int height[N];
int prefix[N];
int suffix[N];

void dfs_pull(int u, int p) {
  branches[u].assign(3, 0);
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      branches[u].push_back(height[c] + 1);
    }
  }
  height[u] = *max_element(branches[u].begin(), branches[u].end());
}

void dfs_push(int u, int p) {
  vector<int> &b = branches[u];
  partial_sort(b.begin(), b.begin() + 3, b.end(), greater<int>());
  for (auto c : adj[u]) {
    if (c != p) {
      branches[c].push_back(b[b[0] == height[c] + 1] + 1);
      dfs_push(c, u);
    }
  }
}

bool dfs_path(int u, int v, int p) {
  height[u] = 0;
  bool found = (u == v);
  for (auto c : adj[u]) {
    if (c != p) {
      if (dfs_path(c, v, u)) {
        found = true;
      } else {
        height[u] = max(height[u], height[c] + 1);
      }
    }
  }

  if (found) {
    path.push_back(u);
  }
  return found;
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  --a, --b;

  fill(adj, adj + n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_pull(0, -1);
  dfs_push(0, -1);

  path.clear();
  dfs_path(a, b, -1);
  int m = path.size();

  bool pivot = false;
  for (int i = 0; i < n; ++i) {
    pivot |= branches[i][3 - 1] >= m - 1;
  }

  for (int i = 0; i < m; ++i) {
    prefix[i] = min(i == 0 ? m - 1 : prefix[i - 1], max(0, m - 1 - height[path[i]] + i));
    suffix[m - 1 - i] = max(i == 0 ? 0 : suffix[m - i], min(m - 1, height[path[m - 1 - i]] - i));
  }

  int l = 0;
  int r = m - 1;
  while (l < r) {
    if (prefix[l] < r) {
      r = prefix[l];
    } else if (suffix[r] > l) {
      l = suffix[r];
    } else {
      break;
    }
  }

  cout << (l >= r && pivot ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}