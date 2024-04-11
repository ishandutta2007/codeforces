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
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5+ 5;
vector<vector<int>> in;
vector<ll> ans;
vector<ll> dp;
vector<ll> sum;
void solve(int l, int r, int &k) {
  if(l == r) {
    ll sum = 0LL;
    for(int i=0;i<=k;i++) {
      ans[l] = max(ans[l], sum + dp[k - i]);
      if(i < in[l].size())
        sum += in[l][i];
    }
  }
  else {
    int m = (l+r)/2;
    vector<ll> temp(k+1);
    for(int i=0;i<=k;i++)
      temp[i] = dp[i];
    for(int i=m+1;i<=r;i++) {
      for(int j=k;j>=in[i].size();j--) {
        dp[j] = max(dp[j], dp[j-in[i].size()] + sum[i]);
      }
    }
    solve(l, m, k);
    for(int i=0;i<=k;i++)
      dp[i] = temp[i];
    for(int i=l;i<=m;i++) {
      for(int j=k;j>=in[i].size();j--) {
        dp[j] = max(dp[j], dp[j-in[i].size()] + sum[i]);
      }
    }
    solve(m+1, r, k);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  in.resize(n), sum.resize(n);
  for(int i=0;i<n;i++) {
    int t; cin >> t;
    in[i].resize(t);
    for(int j=0;j<t;j++) {
      cin >> in[i][j];
      sum[i] += in[i][j];
    }
  }
  dp.resize(k+1);
  ans.resize(n);
  solve(0, n-1, k);
  ll ret = 0LL;
  for(int i=0;i<n;i++)
    ret = max(ret, ans[i]);
  cout << ret << "\n";
}