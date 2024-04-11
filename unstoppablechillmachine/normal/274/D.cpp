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

int n, m;
const int N = 1e5 + 10;
vector<int> g[N], order;
bool used[N];
set<pair<int, int>> st[N];
vector<vector<int>> a;

void dfs(int v) {
  used[v] = true;
  for (int i = 1; i <= n; i++) {
    if (a[i][v] != -1) {
      st[i].erase({a[i][v], v});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][v] == -1) {
      continue;
    }
    while (!st[i].empty() && a[i][v] < (--st[i].end())->F) {
      //cout << "EDGE " << v << ' ' << (--st[i].end())->S << '\n';
      dfs((--st[i].end())->S);
    }
  }
  order.pb(v);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cin >> n >> m;
  a = vector<vector<int>>(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int id = 1; id <= m; id++) {
    for (int i = 1; i <= n; i++) {
      if (a[i][id] != -1) {
        st[i].insert({a[i][id], id});
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(all(order));
  for (int i = 1; i <= n; i++) {
    int prv = 0;
    for (auto v : order) {
      if (a[i][v] != -1) {
        if (a[i][v] < prv) {
          cout << -1 << '\n';
          exit(0);
        }
        prv = a[i][v];
      }
    }
  }
  for (auto it : order) {
    cout << it << ' ';
  }
  cout << '\n';
}