#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

vector<int> adj[N];
int a[N], b[N];

int depth[N], par[N];

void dfs_init(int u) {
  for (auto c : adj[u]) {
    if (c != par[u]) {
      depth[c] = depth[u] + 1;
      par[c] = u;
      dfs_init(c);
    }
  }
}

vector<int> path;
bool in_path[N];
int low, high;

void dfs_path(int u, int p = 0) {
  for (auto c : adj[u]) {
    if (c != p && (c == low || a[c] != b[c])) {
      dfs_path(c, u);
      break;
    }
  }
  path.push_back(u);
  in_path[u] = true;
}

int dist(int u, int v) {
  int d = 0;
  while (u != v) {
    if (depth[u] > depth[v]) {
      u = par[u];
    } else {
      v = par[v];
    }
    ++d;
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int s = find(a + 1, a + n + 1, 0) - a;
  int t = find(b + 1, b + n + 1, 0) - b;

  dfs_init(t);

  for (int u = s; u != t; u = par[u]) {
    swap(a[par[u]], a[u]);
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      if (low == 0 || depth[i] < depth[low]) {
        low = i;
      }
      if (high == 0 || depth[i] > depth[high]) {
        high = i;
      }
    }
  }

  if (low == 0) {
    cout << 0 << " " << depth[s] << "\n";
    exit(0);
  }

  low = par[low];
  dfs_path(high);

  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i] && !in_path[i]) {
      cout << -1 << "\n";
      exit(0);
    }
  }

  if (!in_path[low]) {
    cout << -1 << "\n";
    exit(0);
  }

  int u = path[0], v = path.back(), m = path.size() - 1;
  path.erase(find(path.begin(), path.end(), low));

  int r = 0;
  for ( ; a[path[0]] != b[path[r]]; ++r);
  for (int i = 0; i < m; ++i) {
    if (a[path[i]] != b[path[(i + r) % m]]) {
      cout << -1 << "\n";
      exit(0);
    }
  }

  long long ans = 1 + min(
    dist(s, u) + (long long) (r - 1) * (m + 1) + dist(v, t),
    dist(s, v) + (long long) (m - r - 1) * (m + 1) + dist(u, t)
  );

  if (u > v) {
    swap(u, v);
  }

  cout << u << " " << v << " " << ans << "\n";
}