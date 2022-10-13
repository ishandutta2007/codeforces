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
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
vector<int> par, sz;
vector<ll> num;
int find(int x) {
  if(x == par[x]) return x;
  return par[x] = find(par[x]);
}
void merge(int a, int b, int &r) { //check before if equal components
  int x = find(a), y = find(b);
  if(sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  num[x] = num[x] + num[y] - r;
}
vector<vector<pair<int, int>>> adj;
vector<int> ans;
vector<bool> vis;
//chekc order of dfs...should it be node or parent id?
void dfs(int curr, int &r) {
  vis[curr] = true;
  for(auto next : adj[curr]) {
    int s = find(curr), t = find(next.f);
    if(s != t && num[s] + num[t] >= r) {
      merge(curr, next.f, r);
      ans.push_back(next.s);
      if(!vis[next.f])
        dfs(next.f, r);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r; cin >> n >> m >> r;
  vector<int> a(n);
  ll sum = 0LL;
  for(auto &a : a) cin >> a, sum +=a;
  par.resize(n), sz.resize(n), num.resize(n);
  for(int i=0;i<n;i++) {
    par[i] = i, sz[i] = 1, num[i] = a[i];
  }
  adj.resize(n);
  for(int i=0;i<m;i++) {
    int x, y; cin >> x >> y;
    --x, --y;
    adj[x].push_back({y, i});
    adj[y].push_back({x, i});
    if(a[x] >= r && a[y] >= r) {
      int s = find(x), t = find(y);
      if(s != t) merge(x, y, r), ans.push_back(i);
    }
  }
  if(sum - (n-1)*1LL*r < 0) {
    cout << "NO";
    return 0;
  }
  vis.resize(n);
  for(int i=0;i<n;i++) {
    if(num[find(i)] >= r)
      dfs(i, r);
  }
  for(int i=0;i<n;i++) {
    dfs(i, r);
  }
  if(ans.size() < n-1) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << "\n";
  for(auto &it : ans) {
    cout << it+1 << " ";
  }
  cout << "\n";
}