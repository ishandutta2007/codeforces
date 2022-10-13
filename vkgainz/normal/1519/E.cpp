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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
struct edge {
  int nextId, idx;
};
vector<vector<pair<int, int>>> adj;
vector<int> depth;
vector<pair<int, int>> ans;
int dfs(int curr) {
  vector<int> in;
  for(pair<int, int> next : adj[curr]) {
    int v = next.f, id = next.s;
    if(depth[v] && depth[v] < depth[curr]) continue;
    if(depth[v] == 0) {
      depth[v] = depth[curr] + 1;
      int a = dfs(v);
      if(a == -1) in.push_back(id);
      else ans.push_back({id, a});
    }
    else in.push_back(id);
  }
  while(in.size() >= 2) {
    auto it = in.back();
    auto it2 = in[in.size()-2];
    ans.push_back({it, it2});
    in.pop_back(), in.pop_back();
  }
  if(in.size()) return in[0];
  return -1;
}
pair<ll, ll> get(int a, int b, int c, int d) {
  ll x = a*1LL*d, y = b*1LL*c;
  ll g = __gcd(x, y);
  x /= g, y /= g;
  return {x, y};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  map<pair<ll, ll>, int> m;
  int id = 0;
  adj.resize(2*n);
  depth.resize(2*n);
  for(int i=0;i<n;i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    pair<ll, ll> r = get(a+b, b, c, d), s = get(a, b, c+d, d);
    if(m.find(r) == m.end()) m[r] = id++;
    if(m.find(s) == m.end()) m[s] = id++;
    adj[m[r]].push_back({m[s], i});
    adj[m[s]].push_back({m[r], i});
  }
  for(int i=0;i<2*n;i++) {
    if(depth[i]) continue;
    depth[i] = 1;
    dfs(i);
  }
  cout << ans.size() << "\n";
  for(auto &it : ans) cout << it.f+1 << " " << it.s+1 << "\n";
}