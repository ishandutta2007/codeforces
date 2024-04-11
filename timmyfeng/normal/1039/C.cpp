#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
const int M = 1e9 + 7;

struct disjoint_set_union {

  int par[N];
  int sz[N];

  void init(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
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
    return true;
  }

} dsu;

int add(int& a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

long long code[N];
int pow2[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  pow2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pow2[i] = pow2[i - 1];
    add(pow2[i], pow2[i - 1]);
  }

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) {
    cin >> code[i];
  }

  map<long long, vector<pair<int, int>>> edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[code[u] ^ code[v]].emplace_back(u, v);
  }

  dsu.init(n);
  int ans = 0;
  for (auto& [x, l] : edges) {
    int cnt = n;
    for (auto [u, v] : l) {
      cnt -= dsu.unite(u, v);
    }
    add(ans, pow2[cnt]);

    for (auto [u, v] : l) {
      for (int i : {u, v}) {
        dsu.par[i] = i;
        dsu.sz[i] = 1;
      }
    }
  }
  add(ans, mul(sub(pow2[k], edges.size()), pow2[n]));

  cout << ans << "\n";
}