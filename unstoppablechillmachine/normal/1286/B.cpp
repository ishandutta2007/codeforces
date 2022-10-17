#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 2010;
vector<int> g[N];
int sub[N];

void precalc(int v) {
  sub[v] = 1;
  for (auto u : g[v]) {
    precalc(u);
    sub[v] += sub[u];
  }
}

int c[N], ans[N];

void dfs(int v, vector<int> can) {
  if (c[v] >= sub[v]) {
    cout << "NO\n";
    exit(0);
  }
  ans[v] = can[c[v]];
  can.erase(can.begin() + c[v]);
  for (auto u : g[v]) {
    vector<int> ncan;
    for (int i = 0; i < sub[u]; i++) {
      ncan.pb(can.back());
      can.pop_back();
    }
    reverse(all(ncan));
    dfs(u, ncan);
  }
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;
  int root;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> c[i];
    if (p == 0) {
      root = i;
    }
    else {
      g[p].pb(i);
    }
  }
  precalc(root);
  vector<int> can;
  for (int i = 1; i <= n; i++) {
    can.pb(i);
  }
  dfs(root, can);
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }	
  cout << '\n';
}