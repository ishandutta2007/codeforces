#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 1e5 + 10;
map<int, int> mp[N], cnt[N];
vector<int> g[N];
vector<pair<int, int>> que[N];
int c[N], ans[N];

void dfs(int v, int p = 0) {
  mp[v][c[v]] = 1;
  cnt[v][1] = 1;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v);
      if (SZ(mp[v]) < SZ(mp[u])) {
        mp[v].swap(mp[u]);
        cnt[v].swap(cnt[u]);
      }
      for (auto it : mp[u]) {
        cnt[v][mp[v][it.F]]--;
        if (cnt[v][mp[v][it.F]] == 0) {
          cnt[v].erase(mp[v][it.F]);
        }
        mp[v][it.F] += it.S;
        cnt[v][mp[v][it.F]]++;
      }
    }
  }
  for (auto it : que[v]) {
    for (auto kek : cnt[v]) {
      if (kek.F >= it.F) {
        ans[it.S] += kek.S;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 0; i < m; i++) {
    int v, vl;
    cin >> v >> vl;
    que[v].pb({vl, i});
  }
  dfs(1);
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}