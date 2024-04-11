#include <bits/stdc++.h>

using ll = long long;

const int nmax = 100005;
const int lmax = 20;

int n, m;
int u[nmax], v[nmax], d[nmax];
int rt[nmax];
bool used[nmax];
std::vector<std::pair<int, int>> tree[nmax];
std::vector<std::pair<int, int>> g[nmax];

void init() {
  for (int i = 1; i <= n; i++) {
    rt[i] = i;
  }
}

int root(int u) {
  return rt[u] == u ? u : rt[u] = root(rt[u]);
}

void unite(int u, int v) {
  u = root(u);
  v = root(v);
  rt[u] = v;
}

void mst() {
  std::vector<int> ord(m);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) {
    return d[i] < d[j];
  });
  init();
  for (int i = 0; i < m; i++) {
    if (root(u[ord[i]]) != root(v[ord[i]])) {
      unite(u[ord[i]], v[ord[i]]);
      used[ord[i]] = true;
      tree[u[ord[i]]].push_back({v[ord[i]], d[ord[i]]});
      tree[v[ord[i]]].push_back({u[ord[i]], d[ord[i]]});
    }
  }
}

int par[nmax][lmax];
ll dep[nmax];
int lid[nmax], rid[nmax], tid;

void dfs(int u, int p) {
  lid[u] = ++tid;
  par[u][0] = p;
  for (int i = 1; i < lmax; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto e : tree[u]) {
    if (e.first != p) {
      dep[e.first] = dep[u] + e.second;
      dfs(e.first, u);
    }
  }
  rid[u] = ++tid;
}

bool anc(int u, int v) {
  return lid[u] <= lid[v] && rid[v] <= rid[u];
}

int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (int i = lmax - 1; i >= 0; i--)
    if (par[u][i] != 0 && !anc(par[u][i], v)) u = par[u][i];
  return par[u][0];
}

ll dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

const int dmax = 22;

ll dst[nmax][dmax];

void dijkstra(int u, int id) {
  for (int i = 1; i <= n; i++) {
    dst[i][id] = 1e18;
  }
  dst[u][id] = 0;
  std::set<std::pair<ll, int>> s;
  s.insert({0, u});
  while (!s.empty()) {
    auto it = s.begin();
    int u = (*it).second;
    s.erase(it);
    for (auto e : g[u]) {
      ll nd = dst[u][id] + e.second;
      if (nd < dst[e.first][id]) {
        s.erase({dst[e.first][id], e.first});
        dst[e.first][id] = nd;
        s.insert({dst[e.first][id], e.first});
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> u[i] >> v[i] >> d[i];
    g[u[i]].push_back({v[i], d[i]});
    g[v[i]].push_back({u[i], d[i]});
  }
  mst();
  dfs(1, 0);
  int nxt = 0;
  for (int i = 0; i < m; i++) {
    if (!used[i]) {
      dijkstra(u[i], nxt++);
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    ll res = dist(a, b);
    for (int i = 0; i < nxt; i++) {
      res = std::min(res, dst[a][i] + dst[b][i]);
    }
    std::cout << res << "\n";
  }
  return 0;
}