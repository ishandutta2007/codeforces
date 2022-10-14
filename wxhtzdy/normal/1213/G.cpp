#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 5;

vector<long long> sz(N), p(N);

int root(int u) {
  return u == p[u] ? u : p[u] = root(p[u]);
}

void unite(int u, int v) {
  u = root(u), v = root(v);
  if (sz[u] < sz[v]) {
    swap(u, v);
  }
  sz[v] += sz[u];
  p[u] = v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e.emplace_back(w, u, v);
  }
  sort(e.begin(), e.end());
  vector<pair<int, int>> q(m);
  for (int i = 0; i < m; i++) {
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(q.begin(), q.end());
  for (int i = 0; i < n; i++) {
    sz[i] = 1;
    p[i] = i;
  }
  int j = 0;
  vector<long long> ans(m);
  long long curr = 0;
  for (int i = 0; i < m; i++) {
    while (j < n - 1 && get<0>(e[j]) <= q[i].first) {
      int u = get<1>(e[j]), v = get<2>(e[j]);
      curr -= sz[root(u)] * (sz[root(u)] - 1) / 2;
      curr -= sz[root(v)] * (sz[root(v)] - 1) / 2;
      unite(u, v);
      curr += sz[root(u)] * (sz[root(u)] - 1) / 2;
      j++;
    }
    ans[q[i].second] = curr;
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}