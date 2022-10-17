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
int cnt[N], cl[N];

void precalc(int v, int p = 0) {
  cnt[v] = (cl[v] == 0);
  for (auto u : g[v]) {
    if (u != p) {
      precalc(u, v);
      cnt[v] += cnt[u];
    }
  }
}

void dfs(int v, int p = 0) {
  cout << v << ' ';
  for (auto u : g[v]) {
    if (u != p) {
      if (cnt[u] > 0) {
        cl[u] ^= 1;
        dfs(u, v);
        cout << v << ' ';
        cl[v] ^= 1;
        if (cl[u] == 0) {
          cout << u << ' ' << v << ' ';
          cl[v] ^= 1;
        }
      }
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
    cin >> cl[i];
    if (cl[i] == -1) {
      cl[i] = 0;
    }
  }  
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  precalc(1);
  dfs(1);
  if (cl[1] == 0) {
    cout << g[1][0] << ' ' << 1 << ' ' << g[1][0] << '\n';
  }
}