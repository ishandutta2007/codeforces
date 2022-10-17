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
 
const int MOD = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline int sum(int a, int b) {
  add(a, b);
  return a;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
  int cur = a, ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = mult(ans, cur);
    }
    b >>= 1;
    cur = mult(cur, cur);
  }  
  return ans;
}

int inv(int a) {
  return b_pow(a, MOD - 2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<vector<int>> dist(n + 1, vector<int>(n + 1));
  vector<vector<vector<int>>> sub(n + 1, vector<vector<int>>(n + 1)), lca(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  function<void(int, int, int, int)> dfs = [&](int v, int start, int p, int d) {
    dist[start][v] = d;
    sub[start][v] = {v};
    for (auto u : g[v]) {
      if (u != p) {
        dfs(u, start, v, d + 1);
        for (auto it : sub[start][u]) {
          for (auto it2 : sub[start][v]) {
            lca[start][it][it2] = lca[start][it2][it] = v;
          }
        }
        for (auto it : sub[start][u]) {
          sub[start][v].pb(it);
        }
      }
    }
  };
  for (int v = 1; v <= n; v++) {
    dfs(v, v, 0, 0);
  }
  int r2 = inv(2);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int d1 = 0; d1 <= n; d1++) {
    for (int d2 = 0; d2 <= n; d2++) {
      if (!d2) {
        dp[d1][d2] = 0;
        continue;
      }
      if (!d1) {
        dp[d1][d2] = 1;
        continue;
      }
      dp[d1][d2] = mult(r2, sum(dp[d1 - 1][d2], dp[d1][d2 - 1]));
    }
  }
  int ans = 0;
  for (int s = 1; s <= n; s++) {
    for (int a = 1; a <= n; a++) {
      for (int b = a + 1; b <= n; b++) {
        if (dist[s][b] + dist[b][a] == dist[s][a]) {
          add(ans, 1);
          continue;
        }
        if (dist[s][a] + dist[a][b] == dist[s][b]) {
          continue;
        }
        int kek = lca[s][a][b];
        add(ans, dp[dist[kek][b]][dist[kek][a]]);
      }
    }
  }
  cout << mult(ans, inv(n)) << '\n';
}