#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
const int BLOCK_SZ = 300; 
vector<int> h, b;
vector<ll> dp;
vector<int> pr;
int sz = 1;
vector<ll> seg;
ll query(int l, int r) {
  l+=sz, r+=sz;
  ll ans = -1e18;
  while(l< r) {
    if(l%2) ans = max(ans, seg[l++]);
    if(r%2) ans = max(ans, seg[--r]);
    l/=2, r/=2;
  }
  return ans;
}
void upd(int i, ll x) {
  seg[i+=sz] = x;
  while(i>1) {
    i/=2;
    seg[i] = max(seg[2*i], seg[2*i+1]);
  }
}
int main() {
  int n; cin >> n;
  h.resize(n), b.resize(n);
  for(auto &a : h) cin >> a;
  for(auto &a : b) cin >> a;
  dp.resize(n+1);
  while(sz < n+1) sz *= 2;
  seg.resize(2*sz);
  vector<int> stack;
  pr.resize(n);
  for(int i=0;i<n;i++) {
    while(!stack.empty() && h[stack.back()] >= h[i])
      stack.pop_back();
    if(stack.size()) pr[i] = stack.back() + 1;
    else pr[i] = 0;
    stack.push_back(i);
  }
  //pr[i] stores min j such that min(h[j],...h[i]) = h[i]
  for(int i=1;i<=n;i++) {
    //take in the range of pr[i]
    int lst = pr[i-1] + 1;
    dp[i] = -1e18;
    if(lst == 1) {
      ll x = query(lst, i);
      dp[i] = max(dp[i], x + b[i-1]);
      dp[i] = max(dp[i], 1LL*b[i-1]);
    }
    else {
      dp[i] = dp[lst - 1];
      ll x = query(lst - 1, i);
      dp[i] = max(dp[i], x + b[i-1]);
    }
    upd(i, dp[i]);
    //max(dp[0], dp[1], ..., 
  }
  cout << dp[n] << "\n";
  
}