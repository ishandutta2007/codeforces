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

const int MOD = 998244353;
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline int sum(int a, int b) {
  add(a, b);
  return a;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

const int N = 3e5 + 10;
vector<int> g[N];
int dp[N][3];
//0 - no edges
//1 - have edges, not take
//2 - take

void dfs(int v, int p = 0) {
  dp[v][0] = 1;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v);
      int vl = 0, vl2;
      for (int i = 0; i < 3; i++) {
        add(vl, dp[u][i]);
      }
      vl2 = sum(vl, dp[u][0]);
      int vl3 = sum(dp[u][0], dp[u][1]);
      int to0 = mult(dp[v][0], vl), 
      to1 = sum(mult(dp[v][0], vl2), mult(dp[v][1], sum(vl, vl2))), 
      to2 = sum(mult(dp[v][0], vl3), mult(dp[v][2], (2 * vl3) % MOD + dp[u][2]));
      dp[v][0] = to0;
      dp[v][1] = to1;
      dp[v][2] = to2;           
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    add(ans, dp[1][i]);
  }
  ans--;
  if (ans < 0) {
    ans += MOD;
  }
  cout << ans << '\n';
}