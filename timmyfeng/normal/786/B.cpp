#include <bits/stdc++.h>
using namespace std;

const int N = 300'000;

struct dijkstra {
  long long d;
  int u;

  bool operator<(dijkstra oth) const {
    return d > oth.d;
  }
};

vector<array<int, 2>> adj[N];
long long dist[N];
int child[N][2];
int size_adj;

int build(int l, int r, bool up) {
  if (l == r) {
    return l;
  } else {
    int u = size_adj;
    ++size_adj;

    int m = (l + r) / 2;
    child[u][0] = build(l, m, up);
    child[u][1] = build(m + 1, r, up);

    for (auto i : {0, 1}) {
      if (up) {
        adj[child[u][i]].push_back({u, 0});
      } else {
        adj[u].push_back({child[u][i], 0});
      }
    }

    return u;
  }
}

void update(int u, int l, int r, int a, int b, bool up, int c, int w) {
  if (b < l || r < a) {
    return;
  } else if (a <= l && r <= b) {
    if (up) {
      adj[u].push_back({c, w});
    } else {
      adj[c].push_back({u, w});
    }
  } else {
    int m = (l + r) / 2;
    update(child[u][0], l, m, a, b, up, c, w);
    update(child[u][1], m + 1, r, a, b, up, c, w);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q, s;
  cin >> n >> q >> s;
  size_adj = n;
  --s;

  int root_down = build(0, n - 1, false);
  int root_up = build(0, n - 1, true);

  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      update(root_down, 0, n - 1, v, v, false, u, w);
    } else if (t == 2) {
      int u, l, r, w;
      cin >> u >> l >> r >> w;
      --u, --l, --r;
      update(root_down, 0, n - 1, l, r, false, u, w);
    } else {
      int u, l, r, w;
      cin >> u >> l >> r >> w;
      --u, --l, --r;
      update(root_up, 0, n - 1, l, r, true, u, w);
    }
  }

  fill(dist, dist + size_adj, LLONG_MAX);
  dist[s] = 0;

  priority_queue<dijkstra> que;
  que.push({0LL, s});

  while (!que.empty()) {
    dijkstra u = que.top();
    que.pop();
    if (u.d > dist[u.u]) {
      continue;
    }

    for (auto [c, w] : adj[u.u]) {
      if (u.d + w < dist[c]) {
        dist[c] = u.d + w;
        que.push({dist[c], c});
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << " ";
  }
  cout << "\n";
}