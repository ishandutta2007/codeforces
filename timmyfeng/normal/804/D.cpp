#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> adj[N];

int color[N];
int path[N];
int oth[N];
int sub[N];

vector<long long> sum[N];
vector<int> freq[N];
int diameter[N];

void update(int u, int c) {
  if (path[c] + 1 > path[u]) {
    oth[u] = path[u];
    path[u] = path[c] + 1;
  } else {
    oth[u] = max(oth[u], path[c] + 1);
  }
}

void dfs_pull(int u, int p, int cur) {
  color[u] = cur;
  sub[u] = 1;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u, cur);
      sub[u] += sub[c];
      update(u, c);
    }
  }
}

void dfs_push(int u, int p) {
  if (p != -1) {
    update(u, p);
  }

  for (auto c : adj[u]) {
    if (c != p) {
      if (path[u] == path[c] + 1) {
        swap(path[u], oth[u]);
      }
      dfs_push(c, u);
      if (path[u] < oth[u]) {
        swap(path[u], oth[u]);
      }
    }
  }

  ++freq[color[u]][path[u]];
  sum[color[u]][path[u]] += path[u];
  diameter[color[u]] = max(diameter[color[u]], path[u]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(12);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  fill(color, color + n, -1);
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      dfs_pull(i, -1, i);

      sum[i].resize(sub[i] + 1);
      freq[i].resize(sub[i] + 1);

      dfs_push(i, -1);

      for (int k = 1; k <= sub[i]; ++k) {
        sum[i][k] += sum[i][k - 1];
        freq[i][k] += freq[i][k - 1];
      }
    }
  }

  map<array<int, 2>, double> ans;

  while (q--) {
    int u, v;
    cin >> u >> v;
    u = color[u - 1];
    v = color[v - 1];

    if (u == v) {
      cout << -1 << "\n";
      continue;
    }

    if (sub[u] > sub[v] || (sub[u] == sub[v] && u > v)) {
      swap(u, v);
    }

    if (ans.count({u, v}) == 0) {
      int cap = max(diameter[u], diameter[v]);
      long long expect = 0;

      for (int i = 0; i <= diameter[u]; ++i) {
        int count_u = freq[u][i] - (i == 0 ? 0 : freq[u][i - 1]);
        int count_v = (cap - i - 1 >= 0) ? freq[v][cap - i - 1] : 0;
        long long sum_v = (cap - i - 1 >= 0) ? sum[v][cap - i - 1] : 0;

        expect += (long long) cap * count_u * count_v;
        expect += (long long) count_u * ((i + 1) * (sub[v] - count_v) + (sum[v][sub[v]] - sum_v));
      }

      ans[{u, v}] = (double) expect / sub[u] / sub[v];
    }

    cout << ans[{u, v}] << "\n";
  }
}