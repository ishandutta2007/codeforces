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
int dp[5010][5010];
vector<pair<int, int>> castle;
vector<int> importance, lst;
vector<vector<int>> in;
bool cmp(const int &x, const int &y) { return importance[x] > importance[y]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  castle.resize(n);
  importance.resize(n);
  lst.resize(n);
  in.resize(n);
  for(int i=0;i<n;i++) {
    cin >> castle[i].f >> castle[i].s >> importance[i];
  }
  fill(lst.begin(), lst.end(), -1);
  for(int i=0;i<m;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    lst[v] = max(lst[v], u);
  }
  for(int i=0;i<n;i++) {
    lst[i] = max(lst[i], i);
  }
  for(int i=0;i<n;i++) {
    in[lst[i]].push_back(i);
  }
  for(int i=0;i<n;i++) {
    sort(in[i].begin(), in[i].end(), cmp);
  }
  for(int i=n-1;i>=0;i--) {
    for(int x=0;x<=5005;x++) {
      //x warriors at castle i before we capture it = dp[i][x];
      dp[i][x] = -1000000000;
      if(x < castle[i].f) {
        continue;
      }
      int curr = min(x + castle[i].s, 5005);
      //take none
      dp[i][x] = dp[i+1][curr];
      int sum = 0;
      for(int take=0;take<in[i].size();take++) {
        sum += importance[in[i][take]];
        if(curr - (take + 1) >= 0) {
          dp[i][x] = max(dp[i][x], sum + dp[i+1][curr-(take+1)]);
        }
      }
    }
  }
  if(dp[0][k] < 0) cout << -1 << "\n";
  else cout << dp[0][k] << "\n";
}