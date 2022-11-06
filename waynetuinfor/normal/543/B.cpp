#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 5;

struct Edge {
  int id, cost;
  bool operator>(const Edge& rhs) const {
    return cost > rhs.cost;
  }
};

vector<int> G[maxn];
int N, M, d[maxn][maxn], s1, t1, l1, s2, t2, l2, a, b;

void dijkstra(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 0; i < maxn; ++i) fill(d[i], d[i] + maxn, INT_MAX);
  for (int i = 0; i < M; ++i) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  for (int i = 1; i <= N; ++i) dijkstra(i);
  if (d[s1][t1] > l1) return cout << "-1\n", 0;
  if (d[s2][t2] > l2) return cout << "-1\n", 0;
  int ans = d[s1][t1] + d[s2][t2];
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2) {
        ans = min(ans, d[s1][i] + d[i][j] + d[j][t1] + d[s2][i] + d[j][t2]);
      }
      if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[t2][i] + d[i][j] + d[j][s2] <= l2) {
        ans = min(ans, d[s1][i] + d[i][j] + d[j][t1] + d[t2][i] + d[j][s2]);
      }
    }
  }
  cout << M - ans << '\n';
  return 0;
}

void dijkstra(int st) {
  d[st][st] = 0;
  bool v[maxn];
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  memset(v, false, sizeof(v));
  pq.push((Edge){ st, 0 });
  while (pq.size()) {
    Edge e = pq.top(); pq.pop();
    if (v[e.id]) continue;
    v[e.id] = true;
    for (int u : G[e.id]) {
      if (e.cost + 1 < d[st][u]) d[st][u] = e.cost + 1, pq.push((Edge){ u, d[st][u] });
    }
  }
}