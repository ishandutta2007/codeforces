#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
  T, __gnu_pbds::null_type, Comp,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;

const int N = 400000;

long long ans, cost[N][2];
ordered_set<int> toy[N];
int adj[N][2], par[N];

int p[N], w[N], n;

int dfs(int l, int r) {
  if (l + 1 == r) {
    toy[l].insert(p[l]);
    return l;
  }

  int u = n++;
  int m = min_element(w + l + 1, w + r) - w;
  adj[u][0] = dfs(l, m), adj[u][1] = dfs(m, r);
  par[adj[u][0]] = par[adj[u][1]] = u;

  for (int i = 0; i < 2; ++i) {
    for (auto j : toy[adj[u][i]]) {
      cost[u][i] += toy[adj[u][1 - i]].order_of_key(j);
    }
  }
  ans += min(cost[u][0], cost[u][1]);

  for (int i = l; i < r; ++i) {
    toy[u].insert(p[i]);
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  for (int i = 1; i < n; ++i) {
    cin >> w[i];
  }

  int root = dfs(0, n);

  int q;
  cin >> q;

  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;

    for (int k = 0; k < 2; ++k) {
      for (auto i : {x, y}) {
        int u = i;
        while (u != root) {
          ans -= min(cost[par[u]][0], cost[par[u]][1]);
          int c = (u == adj[par[u]][1]);
          int v = adj[par[u]][1 - c];
          int d = toy[v].order_of_key(p[i]);
          if (k == 0) {
            cost[par[u]][1 - c] -= (int) toy[v].size() - d;
            cost[par[u]][c] -= d;
            toy[u].erase(p[i]);
          } else {
            cost[par[u]][1 - c] += (int) toy[v].size() - d;
            cost[par[u]][c] += d;
            toy[u].insert(p[i]);
          }
          ans += min(cost[par[u]][0], cost[par[u]][1]);
          u = par[u];
        }
      }

      if (k == 0) {
        swap(p[x], p[y]);
      }
    }

    cout << ans << "\n";
  }
}