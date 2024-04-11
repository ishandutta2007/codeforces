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
vector<int> a;
vector<vector<int>> adj;
map<int, int> freq; //compress?
vector<map<int, int>> in;
vector<vector<bool>> workIn;
vector<bool> workOut;
vector<int> f;
vector<int> num;
void dfs(int curr, int par) {
  ++in[curr][a[curr]];
  bool tot = true;
  for(int next : adj[curr]) {
    if(next == par) continue;
    dfs(next, curr);
    workIn[curr].pb(workIn[next].back()&&(in[next][a[curr]] == 0));
    tot &= workIn[curr].back();
    if(!workIn[curr].back()) ++num[curr];
    if(in[next].size() > in[curr].size())
      swap(in[next], in[curr]);
    for(auto &it : in[next]) {
      in[curr][it.f] += it.s;
    }
    in[next].clear();
  }
  f[curr] = in[curr][a[curr]];
  workIn[curr].pb(tot);
}
void dfs2(int curr, int par) {
  int i = 0;
  int x = num[curr];
  for(int next : adj[curr]) {
    if(next == par) continue;
    if(!workIn[curr][i]) --x;
    workOut[next] = workOut[curr] && (x == 0) && (freq[a[next]] == f[next]);
    if(!workIn[curr][i]) ++x;
    ++i;
    dfs2(next, curr);
  }
}

int main() {
  int n; cin >> n;
  a.resize(n);
  num.resize(n);
  for(auto &a : a) cin >> a, --a, ++freq[a];
  adj.resize(n);
  for(int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  in.resize(n);
  workIn.resize(n);
  workOut.resize(n);
  f.resize(n);
  workOut[0] = true;
  dfs(0, -1);
  dfs2(0, -1);
  int ans = 0;
  for(int i=0;i<n;i++) {
    //cout << num[i] << "\n";
    ans += workIn[i].back()&&workOut[i];
  }
  cout << ans << "\n";
}