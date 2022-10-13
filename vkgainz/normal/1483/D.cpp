#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e7 + 5;

int main() {
  int n, m; cin >> n >> m;
  ll l[n][n];
  ll d[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      l[i][j] = 1e18, d[i][j] = 1e18;
    l[i][i] = 0, d[i][i] = 0;
  }
  for(int i=0;i<m;i++) {
    int u, v, w; cin >> u >> v >> w;
    --u, --v;
    l[u][v] = w;
    l[v][u] = w;
    d[u][v] = w;
    d[v][u] = w;
  }
  for(int k=0;k<n;k++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int q; cin >> q;
  ll qu[n][n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++)
      qu[i][j] = -1e18;
  }
  while(q--) {
    int u, v, l; cin >> u >> v >> l;
    --u, --v;
    qu[u][v] = l;
    qu[v][u] = l;
  }
  ll mn[n][n];
  for(int u=0;u<n;u++) {
    for(int y=0;y<n;y++) {
      mn[u][y] = 1e18;
      for(int v=0;v<n;v++) {
        mn[u][y] = min(mn[u][y], d[y][v] - qu[u][v]);
      }
    }
  }
  int ans = 0;
  for(int x=0;x<n;x++) {
    for(int y=0;y<n;y++) {
      if(y <= x || l[x][y] == 1e18) continue; //not an edge
      //min d[x][u] + l[x][y] + d[y][v] - qu[u][v] among all v
      //d[x][u] + l[x][y] is fixed
      //min d[y][v] - qu[u][v] for given y, u
      for(int u=0;u<n;u++) {
        //find optimal v
        ll temp = d[x][u] + l[x][y] + mn[u][y];
        if(temp <= 0) {
          ++ans;
          break;
        }
      }
    }
  }
  cout << ans << "\n";
}