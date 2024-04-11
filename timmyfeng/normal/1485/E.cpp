#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int depth[N], mini[N], maxi[N], a[N], d;
long long child[N], points[N];
vector<int> adj[N], layer[N];

void dfs(int u) {
  mini[depth[u]] = min(mini[depth[u]], a[u]);
  maxi[depth[u]] = max(maxi[depth[u]], a[u]);
  layer[depth[u]].push_back(u);
  d = max(d, depth[u]);

  for (auto c : adj[u]) {
    depth[c] = depth[u] + 1;
    dfs(c);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    fill(adj + 1, adj + n + 1, vector<int>());
    fill(layer, layer + n, vector<int>());
    fill(mini, mini + n, INT_MAX);
    fill(maxi, maxi + n, 0);

    for (int i = 2; i <= n; ++i) {
      int p;
      cin >> p;
      adj[p].push_back(i);
    }

    for (int i = 2; i <= n; ++i) {
      cin >> a[i];
    }

    d = 0;
    dfs(1);

    for (int i = d; i >= 0; --i) {
      for (auto j : layer[i]) {
        child[j] = 0;
        for (auto k : adj[j]) {
          child[j] = max(child[j], points[k]);
        }
        points[j] = child[j] + max(a[j] - mini[i], maxi[i] - a[j]);
      }

      sort(layer[i].begin(), layer[i].end(), [&](int u, int v) {
        return a[u] < a[v];
      });

      long long prefix = LLONG_MIN;
      for (auto j : layer[i]) {
        prefix = max(prefix, child[j] - a[j]);
        points[j] = max(points[j], a[j] + prefix);
      }

      reverse(layer[i].begin(), layer[i].end());

      long long suffix = LLONG_MIN;
      for (auto j : layer[i]) {
        suffix = max(suffix, child[j] + a[j]);
        points[j] = max(points[j], suffix - a[j]);
      }
    }

    cout << points[1] << "\n";
  }
}