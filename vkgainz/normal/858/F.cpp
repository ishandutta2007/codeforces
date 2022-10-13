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
vector<vector<int>> adj;
vector<tuple<int, int, int>> ans;
vector<int> depth;
pair<int, int> dfs(int curr) {
  pair<int, int> ret = {-1, -1};
  vector<pair<int, int>> in;
  for(int next : adj[curr]) {
    if(depth[next] != 0 && depth[next] < depth[curr]) continue;
    else if(depth[next] == 0) {
      depth[next] = depth[curr] + 1;
      pair<int, int> x = dfs(next);
      if(x.f != -1) {
        int a = x.f, b = x.s;
        ans.push_back({curr, a, b});
      }
      else {
        in.push_back({curr,next});
      }
    }
    else 
      in.push_back({curr, next});
  }
  while(in.size() >= 2) {
    auto it = in[in.size()-1];
    auto it2 = in[in.size()-2];
    ans.push_back({it.s, curr, it2.s});
    in.pop_back();
    in.pop_back();
  }
  if(in.size()) return in[0];
  return ret;
}
int main() {
  int n, m; cin >> n >> m;
  adj.resize(n);
  for(int i=0;i<m;i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  depth.resize(n);
  for(int i=0;i<n;i++) {
    if(depth[i]) continue;
    depth[i] = 1;
    dfs(i);
  }
  cout << ans.size() << "\n";
  for(auto &it : ans) {
    cout << get<0>(it)+1 << " "  << get<1>(it)+1  << " " << get<2>(it)+1 << "\n";
  }
}