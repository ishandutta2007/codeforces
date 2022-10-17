#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 998244353;

const int N = 3e5 + 10;
const int LOG = 18;
vector<int> g[N], g2[N], have[N];
int tin[N], tout[N], up[N][LOG], c[N], dp[N][2];
int k, timer;
bool mark[N];

void dfs(int v, int par = 0) {
  tin[v] = ++timer;
  up[v][0] = (par ? par : v);
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v);
    }
  }
  tout[v] = ++timer;
}

int mult(int a, int b) {
  return (a * 1ll *  b) % MOD;
}

int sum(int a, int b) {
  int res = a + b;
  if (res >= MOD) {
    res -= MOD;
  }
  return res;
}

void calc(int v, int par = 0) {
  if (mark[v]) {
    dp[v][1] = 1;
    for (auto u : g2[v]) {
      if (u != par) {
        calc(u, v);
        dp[v][1] = mult(dp[v][1], sum(dp[u][0], dp[u][1]));
      }
    }
  }
  else {
    pair<int, int> kek = {1, 0};
    for (auto u : g2[v]) {
      if (u != par) {
        calc(u, v);
        kek = {mult(kek.F, sum(dp[u][0], dp[u][1])), sum(mult(kek.S, sum(dp[u][0], dp[u][1])), mult(kek.F, dp[u][1]))};
      }
    }
    dp[v][0] = kek.F;
    dp[v][1] = kek.S;
  } 
}

void source() {
  int n;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    have[c[i]].pb(i);
  }
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
  for (int i = 1; i <= k; i++) {
    int min_tin = INF, max_tout = -INF;
    for (auto v : have[i]) {
      min_tin = min(min_tin, tin[v]);
      max_tout = max(max_tout, tout[v]);
    }
    int lca = have[i][0];
    if (tin[lca] > min_tin || tout[lca] < max_tout) {
      for (int j = LOG - 1; j >= 0; j--) {
        int to = up[lca][j];
        if (tin[to] > min_tin || tout[to] < max_tout) {
          lca = to;
        }
      }
      lca = up[lca][0];
    }
    for (auto it : have[i]) {
      assert(tin[lca] <= tin[it] && tout[lca] >= tout[it]);
    }
    for (auto v : have[i]) {
      if (v == lca) {
        continue;
      }
      int cur = up[v][0];
      for (;;) {
        if (c[cur]) {
          if (c[cur] != i) {
            cout << 0;
            exit(0);
          }
          break;
        }
        c[cur] = i;
        if (cur == lca) {
          break;
        }
        cur = up[cur][0];
      }
    }
  }
  int cntV = 0;
  vector<int> used(k + 1), to(n + 1);
  for (int i = 1; i <= n; i++) {
    if (c[i]) {
      if (!used[c[i]]) {
        used[c[i]] = ++cntV;
        mark[cntV] = true;
        //cout << "NEW COLOR " << c[i] << ' ' << cntV << '\n';
      }
      to[i] = used[c[i]];
    }
    else {
      to[i] = ++cntV;
    }
  }
  set<pair<int, int>> st;
  for (int v = 1; v <= n; v++) {
    for (auto u : g[v]) {
      int nv = to[v], nu = to[u];
      if (nv == nu) {
        continue;
      }
      if (nv > nu) {
        swap(nv, nu);
      }
      if (st.find(make_pair(nv, nu)) == st.end()) {
        g2[nv].pb(nu);
        g2[nu].pb(nv);
        st.insert(make_pair(nv, nu));
      }
    }
  }
  /*cout << cntV << '\n';
  for (int i = 1; i <= cntV; i++) {
    cout << mark[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= cntV; i++) {
    for (auto u : g2[i]) {
      cout << u << ' ';
    }
    cout << '\n';
  }*/ 
  calc(1);
  cout << dp[1][1];
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