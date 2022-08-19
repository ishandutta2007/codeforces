/**
 *    author:  tourist
 *    created: 04.06.2020 18:07:11       
**/
#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const int MAGIC = 239;

const int N = 100010;

vector<int> g[N];
bool in_st[N];
bool was[N];

bool dfs(int v) {
  was[v] = true;
  in_st[v] = true;
  for (int u : g[v]) {
    if (was[u]) {
      if (!in_st[u]) {
        in_st[v] = false;
        return false;
      }
    } else {
      if (!dfs(u)) {
        in_st[v] = false;
        return false;
      }
    }
  }
  in_st[v] = false;
  return true;
}

vector<int> vis;
int depth[N];
int md[N];
int md2[N];
int mver[N];
int mver2[N];

void Update(int v, int x, int y) {
  if (x < md[v]) {
    md2[v] = md[v];
    mver2[v] = mver[v];
    md[v] = x;
    mver[v] = y;
  } else {
    if (x < md2[v]) {
      md2[v] = x;
      mver2[v] = y;
    }
  }
}

void solve(int v) {
  vis.push_back(v);
  was[v] = true;
  md[v] = md2[v] = depth[v];
  mver[v] = mver2[v] = v;
  for (int u : g[v]) {
    if (was[u]) {
      assert(depth[u] < depth[v]);
      Update(v, depth[u], u);
    } else {
      depth[u] = depth[v] + 1;
      solve(u);
      Update(v, md[u], mver[u]);
      Update(v, md2[u], mver2[u]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);
    int root = -1;
    for (int iter = 0; iter < min(n, MAGIC); iter++) {
      for (int i = 0; i < n; i++) {
        was[i] = in_st[i] = false;
      }
      if (dfs(order[iter])) {
        root = order[iter];
        break;
      }
    }
    if (root == -1) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      was[i] = false;
    }
    vis.clear();
    depth[root] = 0;
    solve(root);
    vector<bool> is_good(n);
    for (int i : vis) {
      if (i == root) {
        is_good[i] = true;
      } else {
        if (md[i] < depth[i] && md2[i] >= depth[i]) {
          is_good[i] = is_good[mver[i]];
        } else {
          is_good[i] = false;
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (is_good[i]) {
        res.push_back(i);
      }
    }
    if ((int) res.size() * 5 < n) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < (int) res.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << res[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}