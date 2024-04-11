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

const int N = 1e5 + 10;
vector<int> g[N], g2[N], order;
int p[N];
bool used[N];

void dfs(int v, int parent = -1) {
  p[v] = parent;
  for (auto u : g[v]) {
    if (u != parent) {
      dfs(u, v);
    }
  }
  order.pb(v);
}

int dfs2(int v, int parent = -1) {
  int res = v;
  used[v] = true;
  for (auto u : g2[v]) {
    if (u != parent) {
      res = dfs2(u, v);
    }
  }
  return res;
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
      g2[i] = {};
      order = {};
      used[i] = false;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1);
    order.pop_back();
    vector<pair<int, int>> to_del;
    //cout << "KEK" << endl;
    for (auto it : order) {
      if (SZ(g2[it]) < 2 && SZ(g2[p[it]]) < 2) {
        g2[it].pb(p[it]);
        g2[p[it]].pb(it);
      }
      else {
        //cout << it << ' ' << p[it] << '\n';
        to_del.pb({it, p[it]});
      }
    }
    //cout << "KEK" << endl;
    vector<pair<int, int>> to_add;
    int lst = -1;
    for (int i = 1; i <= n; i++) {
      if (!used[i] && SZ(g2[i]) <= 1) {
        if (lst != -1) {
          to_add.pb({lst, i});
        }
        lst = dfs2(i);
        //cout << i << ' ' << lst << ' ' << '\n';
      }
    }
    //cout << SZ(to_del) << ' ' << SZ(to_add) << endl;
    assert(SZ(to_del) == SZ(to_add));
    cout << SZ(to_add) << '\n';
    for (int i = 0; i < SZ(to_add); i++) {
      cout << to_del[i].F << ' ' << to_del[i].S << ' ' << to_add[i].F << ' ' << to_add[i].S << '\n';
    }
  }
}