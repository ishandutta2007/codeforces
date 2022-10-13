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
const int MX = 1e6 + 5;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<pair<int, int>>> adj(n);
  for(int i=0;i<m;i++) {    
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    --u, --v;
    adj[u].pb({v,w}), adj[v].pb({u, w});
  }
  vector<array<ll, 4>> dp(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<4;j++)
      dp[i][j] = 1e18;
  dp[0][0] = 0LL;
  set<pair<pair<ll, int>, int>> pq;
  pq.insert({{0LL, 0}, 0});
  vector<array<bool, 4>> seen(n);
  while(!pq.empty()) {
    auto curr = *pq.begin();
    pq.erase(pq.begin());
    if(seen[curr.s][curr.f.s]) continue;
    seen[curr.s][curr.f.s] = true;
    for(auto next : adj[curr.s]) {
      int v = next.f, w = next.s;
      for(int msk=0;msk<4;msk++) {
        ll cost = curr.f.f + w;
        if((msk&(curr.f.s)) == curr.f.s) {
          int nmsk = msk^curr.f.s;
          if(nmsk&1) cost += w;
          if(nmsk&2) cost -= w;
          if(cost < dp[v][msk]) {
            dp[v][msk] = cost;
            pq.insert({{cost, msk}, v});
          }
        }
      }
    }
  }
  for(int i=1;i<n;i++) {
    printf("%lld ", dp[i][3]);
  }
}