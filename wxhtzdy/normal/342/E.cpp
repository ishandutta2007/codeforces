#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int BLOCK = 300;

int n, tin[100050], tout[100050], tsz;
int par[100050][20];
int dep[100050];
bool was[100050];
vector<int> g[100050];

void dfs(int u, int p) {
  par[u][0] = p;
  for (int i = 1; i < 20; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  tin[u] = ++tsz;
  for(int v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  tout[u] = tsz;
}

bool anc(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (int i = 19; i >= 0; i--) {
    if (par[u][i] > 0 && !anc(par[u][i], v)) {
      u = par[u][i];
    }
  }
  return par[u][0];
}

vector<int> tmp;

int dist[100050];

int dst(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - 2 * dep[l];
}

void calc_dist() {

  deque<int> q;
  for (int i = 1; i <= n; i++) {
    if (was[i] == true) {
      dist[i] = 0;
      q.push_back(i);
    } else {
      dist[i] = 1e9;
    }
  }

  while (!q.empty()) {
    int u = q[0];
    for (int v : g[u]) {
      if (dist[v] == 1e9) {
        dist[v] = dist[u] + 1;
        q.push_back(v);
      }
    }
    q.pop_front();
  }
}

void update() {
  calc_dist();
  tmp.clear();
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int q;
  cin >> n >> q;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  was[1] = true;
  calc_dist();

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u;
      cin >> u;

      was[u] = true;
      tmp.push_back(u);
      if ((int) tmp.size() == BLOCK) {
        update();
      }
    } else {
      int u;
      cin >> u;

      int ans = dist[u];
      for (int v : tmp) {
        ans = min(ans, dst(u, v));
      }
      cout << ans << '\n';
    }
  }

}