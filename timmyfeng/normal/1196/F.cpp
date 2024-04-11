#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int N = 200000;

vector<array<int, 2>> adj[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  min_queue<array<long long, 3>> que;
  map<array<int, 2>, long long> paths;
  vector<int> all;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    all.push_back(w);

    paths[{min(u, v), max(u, v)}] = w;

    que.push({w, u, v});
  }

  sort(all.begin(), all.end());
  long long cap = (t <= m ? all[t - 1] : LLONG_MAX);

  long long ans = 0;
  while (t > 0) {
    auto [d, u, v] = que.top();
    que.pop();
    if (d > paths[{(int) min(u, v), (int) max(u, v)}]) {
      continue;
    }

    ans = d;
    --t;

    for (int z = 0; z < 2; ++z) {
      for (auto [c, w] : adj[u]) {
        if (c != v && w < cap) {
          array<int, 2> key = {min(c, (int) v), max(c, (int) v)};
          if (paths.count(key) == 0 || d + w < paths[key]) {
            paths[key] = d + w;
            que.push({d + w, c, v});
          }
        }
      }
      swap(u, v);
    }
  }

  cout << ans << "\n";
}