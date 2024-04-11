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

const int N = 2e5 + 10;
vector<int> g[N];
int a[N];
map<int, int> have[N], all_cnt;
map<pair<int, int>, bool> f;
bool bad[N];

void dfs(int v, int pr = 0) {
  bad[v] = false;
  for (auto u : g[v]) {
    if (u != pr) {
      dfs(u, v);
      bad[v] |= bad[u];
      if (SZ(have[v]) < SZ(have[u])) {
        have[v].swap(have[u]);
      }
      for (auto it : have[u]) {
        have[v][it.F] += it.S;
      }
    }
  }
  if (have[v].count(a[v])) {
    bad[v] = true;
  }
  have[v][a[v]]++;
  int cc = 0;
  if (pr) {
    if (have[v].count(a[pr])) {
      cc = have[v][a[pr]];
    }
    if (cc <= all_cnt[a[pr]] - 2) {
      f[{pr, v}] = true;
    }
  }
}

int ans;

void dfs2(int v, int pr = 0, bool is_pr_bad = false) {
  if (all_cnt[a[v]] == 1 && !is_pr_bad && !bad[v]) {
    //cerr << v << '\n';
    ans++;
  }
  int l = 0, r = SZ(g[v]) - 1;
  for (int i = 0; i < SZ(g[v]); i++) {
    if (g[v][i] != pr && bad[g[v][i]]) {
      l = max(l, i);
      r = min(r, i);
    }
  }
  for (int i = l; i <= r; i++) {
    if (g[v][i] != pr) {
      dfs2(g[v][i], v, is_pr_bad | f[{v, g[v][i]}]);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_cnt[a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  dfs2(1);
  cout << ans << '\n';
}