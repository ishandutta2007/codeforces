#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct ST {
  vector<int> t, f;
  ST(int n) {
    t.resize(4 * n + 10);
    f.resize(4 * n + 10);
  }
  void push(int v, int l, int r) {
    int len1 = (r + l) / 2 - l + 1, len2 = r - (r + l) / 2;
    f[2 * v] += f[v];
    f[2 * v + 1] += f[v];
    t[2 * v] += f[v] * len1;
    t[2 * v + 1] += f[v] * len2;
    f[v] = 0;
  }
  void update(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      f[v] += delta;
      t[v] += delta * (r - l + 1);
      return;
    }
    int mid = (l + r) / 2;
    push(v, l, r);
    update(2 * v, l, mid, a, b, delta);
    update(2 * v + 1, mid + 1, r, a, b, delta);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
  int get(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
      return 0;
    }
    if (l >= a && r <= b) {
      return t[v];
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    return get(2 * v, l, mid, a, b) + get(2 * v + 1, mid + 1, r, a, b);
  }
};

const int N = 1e5 + 10;
const int LOG = 18;
vector<int> g[N], order;
int sz[N], tin[N], tout[N], h[N], up[N][LOG], timer;
pair<int, int> cc[N];

void dfs(int v, int par = 0, int curh = 0) {
  order.pb(v);
  sz[v] = 1;
  tin[v] = ++timer;
  h[v] = curh;
  up[v][0] = (par ? par : v);
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v, curh + 1);
      sz[v] += sz[u];
    }
  }  
  tout[v] = ++timer;
}

bool ancestor(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (ancestor(a, b)) {
    return a;
  }
  if (ancestor(b, a)) {
    return b;
  }
  for (int i = LOG - 1; i >= 0; i--) {
    if (!ancestor(up[a][i], b)) {
      a = up[a][i];
    }
  }
  return up[a][0];
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

void source() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  for (int i = 1; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    cc[order[i]] = {i + 1, i + sz[order[i]]};
  }
  ST tree(n);
  for (int test = 0; test < q; test++) {
    int k, m, root;
    cin >> k >> m >> root;
    vector<pair<int, int>> arr(k);
    for (auto &it : arr) {
      cin >> it.S;
      int L = lca(it.S, root);
      it.F = h[it.S] + h[root] - 2 * h[L];
    }
    sort(all(arr));
    vector<int> kek(k);
    for (int i = 0; i < k; i++) {
      int L = lca(arr[i].S, root);
      int ff;
      if (L == 1) {
        ff = 0;
      }
      else {
        ff = tree.get(1, 1, n, cc[up[L][0]].F, cc[up[L][0]].F);
      }
      kek[i] = -(tree.get(1, 1, n, cc[arr[i].S].F, cc[arr[i].S].F) + tree.get(1, 1, n, cc[root].F, cc[root].F) - ff - tree.get(1, 1, n, cc[L].F, cc[L].F));
    }
    for (int i = 0; i < k; i++) {
      int L = lca(arr[i].S, root);
      int ff;
      if (L == 1) {
        ff = 0;
      }
      else {
        ff = tree.get(1, 1, n, cc[up[L][0]].F, cc[up[L][0]].F);
      }
      kek[i] += tree.get(1, 1, n, cc[arr[i].S].F, cc[arr[i].S].F) + tree.get(1, 1, n, cc[root].F, cc[root].F) - ff - tree.get(1, 1, n, cc[L].F, cc[L].F);
      tree.update(1, 1, n, cc[arr[i].S].F, cc[arr[i].S].S, 1);  
    }
    vector<vector<int>> dp(k + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j <= m; j++) {
        if (j < m) {
          add(dp[i + 1][j + 1], dp[i][j]);
        }
        if (kek[i] < j) {
          add(dp[i + 1][j], mult(dp[i][j], j - kek[i]));
        }
      }
    }
    int ans = 0;
    for (int cnt = 1; cnt <= m; cnt++) {
      add(ans, dp[k][cnt]);
    }
    cout << ans << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}