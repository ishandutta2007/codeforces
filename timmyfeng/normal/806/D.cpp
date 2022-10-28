#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;

struct dijkstra {
  long long d;
  int u;

  bool operator<(dijkstra oth) const {
    return d > oth.d;
  }
};

long long dist[N];
int perish[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int optimal = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cin >> perish[i][j];
      perish[j][i] = perish[i][j];
      optimal = min(optimal, perish[i][j]);
    }
  }

  priority_queue<dijkstra> que;
  for (int i = 0; i < n; ++i) {
    int min_p = INT_MAX;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        perish[i][j] -= optimal;
        min_p = min(min_p, perish[i][j]);
      }
    }
    dist[i] = min_p * 2;
    que.push({dist[i], i});
  }

  while (!que.empty()) {
    dijkstra u = que.top();
    que.pop();

    if (u.d > dist[u.u]) {
      continue;
    }

    for (int c = 0; c < n; ++c) {
      if (u.d + perish[u.u][c] < dist[c]) {
        dist[c] = u.d + perish[u.u][c];
        que.push({dist[c], c});
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << dist[i] + (long long) (n - 1) * optimal << "\n";
  }
}