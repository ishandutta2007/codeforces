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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e5 + 5;
vector<vector<int>> adj;
vector<int> sz;
vector<int> fib;
struct chash {
  int operator() (pair<int, int> x) const { return x.first * 43 + x.second; }
};
gp_hash_table<pair<int, int>, int, chash> stop; //use gt_hash
void init_size(int curr, int par) {
  sz[curr] = 1;
  for(int next : adj[curr]) {
    if(stop[make_pair(curr, next)] || next == par) continue;
    init_size(next, curr);
    sz[curr] += sz[next];
  }
}
bool dfs(int curr, int par, int k) {
  init_size(curr, par);
  queue<pair<int, int>> in;
  in.push(make_pair(curr, par));
  while(!in.empty()) {
    auto curr = in.front();
    in.pop();
    if(k >= 2 && sz[curr.f] == fib[k-1]) {
      stop[make_pair(curr.f, curr.s)] = 1;
      stop[make_pair(curr.s, curr.f)] = 1;
      return dfs(curr.f, curr.s, k-1) && dfs(curr.s, curr.f, k-2);   
    }
    if(k >= 2 && sz[curr.f] == fib[k-2]) {
      stop[make_pair(curr.f, curr.s)] = 1;
      stop[make_pair(curr.s, curr.f)] = 1;
      return dfs(curr.f, curr.s, k-2) && dfs(curr.s, curr.f, k-1);
    }
    for(int next : adj[curr.f]) {
      pair<int, int> x = make_pair(curr.f, next);
      if(stop[x] == 1 || next == curr.s) continue;
      in.push({next, curr.f});
    }
  }
  if(fib[k] == 1 && sz[curr] == 1) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  adj.resize(n);
  sz.resize(n);
  for(int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  fib.push_back(1);
  fib.push_back(1);
  while(true) {
    fib.push_back(fib.back()+fib[fib.size()-2]);
    if(fib.back()>n) break;
  }
  for(int i=0;i<fib.size();i++) {
    if(fib[i] == n) {
      if(dfs(0, -1, i)) cout << "YES" << "\n";
      else cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
}