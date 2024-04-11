#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> g[100050];
int par[100050][20], dep[100050], sz[100050];
int tin[100050], tout[100050], tsz;

void dfs(int u, int p) {
  tin[u] = ++tsz;
  par[u][0] = p;
  for (int i = 1; i < 20; i++) {
    if (par[u][i - 1]) par[u][i] = par[par[u][i - 1]][i - 1];
  }

  for (int v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
      sz[u] += sz[v] + 1;
    }
  }
  tout[u] = ++tsz;
}

int dizi(int u, int k) {
  for (int i = 19; i >= 0; i--) {
    if (k & (1 << i)) {
      u = par[u][i];
    }
  }
  return u;
}

bool predak(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  if (predak(v, u)) return v;
  for (int i = 19; i >= 0; i--) {
    if (par[u][i] && dep[par[u][i]] >= dep[v]) {
      u = par[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, -1);

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;

    if (a == b) {
      cout << n << '\n';
      continue;
    }

    if (dep[a] < dep[b]) swap(a, b);
    if (predak(b, a)) {
      if (dep[b] % 2 != dep[a] % 2) {
        cout << 0 << '\n';
      } else {
        int cale = dizi(a, (dep[a] - dep[b]) / 2 - 1);
        cout << sz[par[cale][0]] - sz[cale] << '\n';
      }
      continue;
    }

    int L = lca(a, b);
    int cale_a = dizi(a, dep[a] - dep[L] - 1);
    int cale_b = dizi(b, dep[b] - dep[L] - 1);
    if (dep[a] == dep[b]) {
      cout << n - sz[cale_a] - sz[cale_b] - 2 << '\n';
      continue;
    }

    int dif = dep[a] - dep[L] + dep[b] - dep[L];
    if (dif % 2 == 1) {
      cout << 0 << '\n';
      continue;
    }
    int ko = dizi(a, dif / 2);
    int sin = dizi(a, dif / 2 - 1);
    cout << sz[ko] - sz[sin] << '\n';
  }
}