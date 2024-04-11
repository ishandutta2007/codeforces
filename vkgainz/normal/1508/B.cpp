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
ll tpow[61];
ll eval(int x) {
  if(x == -1) return tpow[0];
  if(x > 60) return 2e18;
  return tpow[x];
}
vector<int> solve(int n, ll k, int add) {
  vector<int> ans;
  ll num = 0LL;
  for(int pl = 0; pl < n; pl++) {
    num += eval(n-pl-2);
    if(num >= k) {
      for(int i=pl;i>=0;i--) {
        ans.push_back(add+i);
      }
      vector<int> psh = solve(n-pl-1, k - (num - eval(n-pl-2)), add+pl+1); //check this
      ans.insert(ans.end(), psh.begin(), psh.end());
      psh.clear();
      break;
    }
    else {
      continue;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  tpow[0] = 1LL;
  for(int i=1;i<=60;i++) {
    tpow[i] = tpow[i-1]*1LL*2;
  }
  int t; cin >> t;
  while(t--) {
    int n; ll k;
    cin >> n >> k;
    if(eval(n-1) < k) {
      cout << -1 << "\n";
      continue;
    }
    vector<int> ans = solve(n, k, 0);
    for(int i=0;i<n;i++) {
      cout << ans[i]+1 << " ";
    }
    cout << "\n";
  }
}