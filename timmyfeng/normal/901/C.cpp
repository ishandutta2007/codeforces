#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

vector<int> adj[N];
int64_t res[N];
int64_t ans[N];
int color[N];
int par[N];

void dfs(int u) {
  color[u] = 1;
  for (auto c : adj[u]) {
    if (c != par[u]) {
      if (color[c] == 1) {
        int mn = u;
        int mx = u;
        int cur = u;
        while (cur != c) {
          cur = par[cur];
          mn = min(mn, cur);
          mx = max(mx, cur);
        }
        res[mn] = mx;
      } else if (color[c] == 0) {
        par[c] = u;
        dfs(c);
      }
    }
  }
  color[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  fill(res + 1, res + n + 1, n + 1);
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0) {
      dfs(i);
    }
  }

  for (int i = n - 1; i >= 1; --i) {
    res[i] = min(res[i], res[i + 1]);
  }

  int q;
  cin >> q;
  vector<array<int, 3>> queries;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    queries.push_back({r, l, i});
  }
  sort(queries.begin(), queries.end());

  int ptr = 1;
  for (auto [r, l, i] : queries) {
    while (ptr <= r && res[ptr] <= r) {
      res[ptr] += res[ptr - 1] - ptr;
      ++ptr;
    }
    int64_t len = r - max(l, ptr) + 1;
    if (l <= ptr) {
      ans[i] = res[ptr - 1] - res[l - 1] + len * (len + 1) / 2;
    } else {
      ans[i] = len * (len + 1) / 2;
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}