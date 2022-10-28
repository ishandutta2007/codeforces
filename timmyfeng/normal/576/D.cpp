#include <bits/stdc++.h>
using namespace std;

const int N = 150;
const int L = 30;

vector<bitset<N>> mul(vector<bitset<N>> a, vector<bitset<N>> b) {
  int n = a.size();
  vector<bitset<N>> c(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j]) {
        c[i] |= b[j];
      }
    }
  }
  return c;
}

bitset<N> mul(vector<bitset<N>> a, bitset<N> b) {
  int n = a.size();
  bitset<N> c;
  for (int i = 0; i < n; ++i) {
    if (b[i]) {
      c |= a[i];
    }
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  for (auto &i : edges) {
    int u, v, d;
    cin >> u >> v >> d;
    i = {d, --u, --v};
  }
  sort(edges.begin(), edges.end());

  int flights = 0, ans = INT_MAX;
  vector<bitset<N>> adj(n);
  bitset<N> visited;
  visited[0] = true;

  for (int i = 0; i < m; ++i) {
    auto [d, u, v] = edges[i];

    vector<bitset<N>> matrix = adj;
    int delta = d - flights;
    while (delta > 0) {
      if (delta % 2 == 1) {
        visited = mul(matrix, visited);
      }
      delta /= 2;
      matrix = mul(matrix, matrix);
    }
    flights = d;

    adj[u][v] = true;
    bitset<N> reachable = visited;
    for (int j = 0; j < n && !reachable[n - 1]; ++j) {
      reachable = mul(adj, reachable);
      ++d;
    }

    if (reachable[n - 1]) {
      ans = min(ans, d);
    }
  }

  if (ans == INT_MAX) {
    cout << "Impossible\n";
  } else {
    cout << ans << "\n";
  }
}