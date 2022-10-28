#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 2;

struct dijkstra {
  long long d;
  int u;
  bool operator<(dijkstra oth) const {
    return d > oth.d;
  }
};

vector<array<int, 2>> adj[N];
long long dist[N];
int indices[N];
int x[N];
int y[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int xs, ys, xf, yf;
  cin >> xs >> ys >> xf >> yf;
  adj[m].push_back({m + 1, abs(xf - xs) + abs(yf - ys)});

  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    adj[m].push_back({i, min(abs(xs - x[i]), abs(ys - y[i]))});
    adj[i].push_back({m + 1, abs(xf - x[i]) + abs(yf - y[i])});
  }

  iota(indices, indices + m, 0);

  for (int k = 0; k < 2; ++k) {
    sort(indices, indices + m, [&](int a, int b) {
      return x[a] < x[b];
    });
    for (int i = 0; i < m; ++i) {
      if (i > 0) {
        adj[indices[i]].push_back({indices[i - 1], x[indices[i]] - x[indices[i - 1]]});
      }
      if (i < m - 1) {
        adj[indices[i]].push_back({indices[i + 1], x[indices[i + 1]] - x[indices[i]]});
      }
    }
    swap(x, y);
  }

  fill(dist, dist + m + 2, LLONG_MAX);
  priority_queue<dijkstra> que;
  que.push({0, m});
  dist[m] = 0;

  while (!que.empty()) {
    dijkstra s = que.top();
    que.pop();
    if (s.d > dist[s.u]) {
      continue;
    }

    for (auto [c, w] : adj[s.u]) {
      if (s.d + w < dist[c]) {
        dist[c] = s.d + w;
        que.push({dist[c], c});
      }
    }
  }

  cout << dist[m + 1] << "\n";
}