#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

bool visited[N], ans[N], used[N];
vector<pair<int, bool>> adj[N];
vector<int> group;

bool dfs(int u) {
  bool ok = true;
  visited[u] = true;
  group.push_back(u);
  for (auto [c, w] : adj[u]) {
    if (!visited[c]) {
      used[c] = used[u] ^ w;
      ok &= dfs(c);
    } else {
      ok &= (used[c] == (used[u] ^ w));
    }
  }
  return ok;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    char c;
    int u, v;
    cin >> u >> v >> c;
    --u, --v;

    adj[u].push_back({v, c == 'R'});
    adj[v].push_back({u, c == 'R'});
  }

  fill(ans, ans + n, true);

  for (int k = 0; k < 2; ++k) {
    fill(visited, visited + n, false);
    bool ok = true;

    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        group.clear();
        ok &= dfs(i);

        int count = 0;
        for (auto u : group) {
          count += used[u];
        }

        if (count * 2 > (int) group.size()) {
          for (auto u : group) {
            used[u] ^= true;
          }
        }
      }
    }

    if (ok && count(used, used + n, true) < count(ans, ans + n, true)) {
      copy(used, used + n, ans);
    }

    for (int i = 0; i < n; ++i) {
      for (auto &[j, c] : adj[i]) {
        c ^= true;
      }
    }
  }

  if (count(ans, ans + n, true) == n) {
    cout << -1 << "\n";
  } else {
    cout << count(ans, ans + n, true) << "\n";
    for (int i = 0; i < n; ++i) {
      if (ans[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
  }
}