#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
vector<int> g[N];
int cc[N], mx;

void dfs(int v, int p = 0, int curh = 1) {
  cc[curh]++;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, curh + 1);
    }
  }
  mx = max(mx, curh);
}

signed main() {
  ios_base::sync_with_stdio(false);
  int n, cnt, sum;
  cin >> n >> cnt >> sum;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  int cur_take = 0, cur_sum = 0, d = mx;
  int ans = 0;
  for (int u = mx; u >= 2; u--) {
    if (d > u) {
      cur_take = cur_sum = 0;
      d = u;
    }
    else {
      cur_take -= cc[u + 1];
      cur_sum -= cur_take;  
    }
    while (d >= 2 && cc[d] * (u - d) + cur_sum <= sum) {
      cur_sum += cc[d] * (u - d);
      cur_take += cc[d];
      d--;
    }
    //cout << u << ' ' << d << ' ' << cur_sum << ' ' << cur_take << '\n';
    if (d > 1) {
      ans = max(ans, cur_take + (sum - cur_sum) / (u - d));
    }
    else {
      ans = max(ans, cur_take);
    }
  }
  ans = min(ans, cnt);
  cout << ans << '\n';
  //cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}