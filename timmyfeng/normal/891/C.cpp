#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

struct union_find {

  int par[N];
  int sz[N];

  vector<array<int, 2>> stk;

  void init(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
  }

  int find(int u) {
    if (par[u] != u) {
      return find(par[u]);
    }
    return par[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
    stk.push_back({u, v});
    return true;
  }

  void roll_back() {
    auto [u, v] = stk.back();
    stk.pop_back();
    sz[v] -= sz[u];
    par[u] = u;
  }

} dsu;

bool ans[N];
int u[N];
int v[N];
int w[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i], --v[i];
  }

  int q;
  cin >> q;
  fill(ans, ans + q, true);
  vector<array<int, 3>> events;
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int e;
      cin >> e;
      events.push_back({w[e], i, e});
    }
  }

  for (int i = 1; i <= m; ++i) {
    events.push_back({w[i], q, i});
  }
  sort(events.begin(), events.end());

  int pre = 0;
  int cnt = 0;
  dsu.init(n);
  for (auto [c, i, e] : events) {
    if (i != pre && pre != q) {
      while (cnt > 0) {
        dsu.roll_back();
        --cnt;
      }
    }

    bool res = dsu.unite(u[e], v[e]);
    if (i != q) {
      ans[i] &= res;
      cnt += res;
    }
    pre = i;
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << "\n";
  }
}