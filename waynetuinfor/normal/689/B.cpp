#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int a[maxn], n, d[maxn];
struct Edge { int to, cost; };
struct Heap {
  int id, cost;
  bool operator>(const Heap& rhs) const {
    return cost > rhs.cost;
  }
};
vector<Edge> G[maxn];
priority_queue<Heap, vector<Heap>, greater<Heap>> pq;
bool v[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], G[i].push_back((Edge){ a[i], 1 });
  for (int i = 1; i <= n; ++i) d[i] = i - 1;
  for (int i = 1; i <= n; ++i) pq.push((Heap){ i, d[i] });
  while (pq.size()) {
    Heap h = pq.top(); pq.pop();
    if (v[h.id]) continue;
    v[h.id] = true;
    for (Edge e : G[h.id]) {
      if (d[e.to] > e.cost + h.cost) {
        d[e.to] = e.cost + h.cost;
        pq.push((Heap){ e.to, d[e.to] });
      }
      if (d[e.to] > h.cost + abs(e.to - h.id)) {
        d[e.to] = h.cost + abs(e.to - h.id);
        pq.push((Heap){ e.to, d[e.to] });
      }
    }
    for (int i = max(1, h.id - 1); i <= min(n, h.id + 1); ++i) {
      if (h.cost + abs(i - h.id) < d[i]) {
        d[i] = h.cost + abs(i - h.id);
        pq.push((Heap){ i, d[i] });
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
  cout << '\n';
  return 0;
}