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
const int MX = 2e5 + 5;
vector<vector<int>> adj;
vector<vector<int>> dist;
vector<vector<int>> par;
vector<ll> inv;
ll ans[401][401];
ll mod = 998244353;
//prove if dist(r, s) > 1 ans = 0??
ll solve(int x, int y, int n) {
  vector<int> path;
  int curr = y;
  while(curr != x) {
    path.push_back(curr);
    curr = par[x][curr];
  }
  path.push_back(x);

  vector<int> num;
  vector<bool> vis;
  queue<int> in;
  num.assign(n, 0);
  vis.assign(n, false);
  for(int x : path) {
    in.push(x);
    num[x] = 1;
    vis[x] = true;
  }

  while(!in.empty()) {
    int curr = in.front();
    in.pop();
    for(int next : adj[curr]) {
      if(dist[next][x] == dist[curr][x] + 1 && dist[next][y] == dist[curr][y] + 1) {
        ++num[next];
        if(!vis[next]) in.push(next);
        vis[next] = true;
      }
    }
  }
  ll ret = 1LL;
  for(int i=0;i<n;i++) {
    ret *= num[i];
    ret %= mod;
  }
  return ret;
}
int main() {
  int n, m; cin >> n >> m;
  adj.resize(n);
  for(int i=0;i<m;i++) {
    int x, y; cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dist.resize(n);
  par.resize(n);
  for(int i=0;i<n;i++) {
    queue<int> q;
    q.push(i);
    dist[i].assign(n, 1000000);
    par[i].assign(n, -1);
    dist[i][i] = 0;
    par[i][i] = i;
    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      for(int next : adj[curr]) {
        if(dist[i][curr] + 1 < dist[i][next]) {
          dist[i][next] = dist[i][curr] + 1;
          par[i][next] = curr;
          q.push(next);
        }
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      ans[i][j] = solve(i, j, n);
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}