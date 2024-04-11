#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 2e5 + 10;
vector<int> g[N];
int sz[N], par[N], h[N];

void dfs(int v, int p = 0, int ch = 0) {
  sz[v] = 1;
  par[v] = p;
  h[v] = ch;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, ch + 1);
      sz[v] += sz[u];
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }   
  dfs(1);
  vector<int> srt;
  for (int i = 2; i <= n; i++) {
    srt.pb(h[i] - sz[i] + 1);
  }
  sort(srt.rbegin(), srt.rend());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += srt[i];
  }
  cout << ans << '\n';
}