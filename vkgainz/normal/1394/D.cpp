#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5+ 5;

vi t, h;
vvi adj;
vll dpTot, dpUp, dpDown;
void dfs(int curr, int par) {
  ll sumUp = 0LL, sumDown = 0LL;
  vector<ll> in;
  ll sumEq = 0LL;
  int leaf = 0;
  int numUp = 0, numDown = 0, numEq = 0;
  for(int next : adj[curr]) {
    if(next == par) continue;
    dfs(next, curr);
    if(h[next] == h[curr]) {
      in.push_back(t[curr] + min(t[next] + dpTot[next], dpDown[next]) - (t[curr] + min(t[next] + dpTot[next], dpUp[next])));
      sumEq += t[curr] + min(t[next] + dpTot[next], dpUp[next]);
      ++numEq;
    }
    else if(h[next] < h[curr]) 
      sumUp += t[curr] + min(t[next] + dpTot[next], dpUp[next]), ++numUp;
    else
      sumDown += t[curr] + min(t[next] + dpTot[next], dpDown[next]), ++numDown;
    ++leaf;
  }
  sort(in.begin(), in.end());
  dpUp[curr] = 1e18, dpDown[curr] = 1e18;
  if(leaf == 0) {
    dpTot[curr] = 0LL;
    return;
  }
  dpTot[curr] = 1e18;
  for(int a=0;a<=numEq;a++) {
    int totUp = numUp + (numEq - a), totDown = numDown + a;
    int x = min(totUp, totDown);
    if(a>0) sumEq += in[a-1];
    ll cost = sumUp + sumDown + sumEq - x*1LL*t[curr];
    dpTot[curr] = min(dpTot[curr], cost);
    if(totUp - x) {
      dpUp[curr] = min(dpUp[curr], cost);
    }
    if(totDown - x) {
      dpDown[curr] = min(dpDown[curr], cost);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  t.resize(n), h.resize(n), dpTot.resize(n), dpUp.resize(n), dpDown.resize(n), adj.resize(n);
  for(auto &t : t) cin >> t;
  for(auto &h : h) cin >> h;
  for(int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(0, -1);
  cout << dpTot[0] << "\n";

}