#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

mt19937 rnd(239);

const int N = 3e5 + 10;
const int L = 19;
vector<int> g[N];
int pos[N], sz[N], up[L][N], tin[N], tout[N], timer, timer2;

void dfs(int v, int p = 1) {
  up[0][v] = p;
  pos[v] = ++timer;
  tin[v] = ++timer2;
  sz[v] = 1;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
  }
  tout[v] = ++timer2;
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (anc(a, b)) {
    return a;
  }
  if (anc(b, a)) {
    return b;
  }
  for (int i = L - 1; i >= 0; i--) {
    if (!anc(up[i][a], b)) {
      a = up[i][a];
    }
  }
  return up[0][a];
}

int t[N];
inline void update(int v, int val) {
  for (; v < N; v += v & (-v)) {
    t[v] ^= val;
  }
}

inline void update(int l, int r, int val) {
  update(l, val);
  update(r + 1, val);
}

inline int get(int v) {
  int result = 0;
  for (; v > 0; v -= v & (-v)) {
    result ^= t[v];
  }
  return result;
} 

int hs[N], a[N], u[N], v[N], lo[N], hi[N], vl[N], l[N], w[N];
vector<int> add[N], que[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    hs[i] = rnd();
    if (hs[i] < 0) {
      hs[i] *= -1;
    } 
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add[a[i]].pb(i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  for (int i = 1; i < L; i++) {
    for (int j = 1; j <= n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
  for (int i = 1; i <= m; i++) {
    int r;
    cin >> u[i] >> v[i] >> l[i] >> r;
    lo[i] = l[i] - 1, hi[i] = r + 1;
    w[i] = lca(u[i], v[i]);
    que[r].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    for (auto it : add[i]) {
      update(pos[it], pos[it] + sz[it] - 1, hs[i]);
    }
    for (auto it : que[i]) {
      vl[it] = get(pos[u[it]]) ^ get(pos[v[it]]);
      if (a[w[it]] <= i) {
        vl[it] ^= hs[a[w[it]]];
      }
    }
  }
  for (int iter = 0; iter < L; iter++) {
    for (int i = 1; i < N; i++) {
      t[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
      que[i] = {};
    }
    for (int i = 1; i <= m; i++) {
      if (lo[i] + 1 < hi[i]) {
        que[(lo[i] + hi[i]) / 2 - 1].pb(i);
      }
    }
    for (int i = 0; i <= n; i++) {
      for (auto it : add[i]) {
        update(pos[it], pos[it] + sz[it] - 1, hs[i]);
      } 
      for (auto it : que[i]) {
        int current = get(pos[u[it]]) ^ get(pos[v[it]]);
        if (a[w[it]] <= i) {
          current ^= hs[a[w[it]]];
        }
        if (current != vl[it]) {
          lo[it] = (lo[it] + hi[it]) / 2;
        }
        else {
          hi[it] = (lo[it] + hi[it]) / 2;
        }
      } 
    }
  }
  for (int i = 1; i <= m; i++) {
    if (lo[i] < l[i]) {
      cout << -1 << '\n';
    }
    else {
      cout << lo[i] << '\n';
    }
  } 
}