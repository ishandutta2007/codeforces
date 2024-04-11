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
const int MX = 400005;
vector<vector<ll>> dp;
vector<int> a;
vector<int> freq;
ll x;
void solve(int lo, int hi, int optl, int optr, int k) {
  if(lo > hi) return;
  int mid = (lo+hi)/2;
  int best = optl;
  ll curr = x;
  ll mn = 1e18;
  for(int i = optl; i <= min(mid, optr); i++) {
    if(curr + dp[i-1][k-1] < mn) {
      mn = curr + dp[i-1][k-1];
      best = i;
    }
    --freq[a[i-1]];
    curr -= freq[a[i-1]];
  }
  for(int i = min(mid, optr); i >= optl; i--) {
    curr += freq[a[i-1]];
    ++freq[a[i-1]];
  }
  dp[mid][k] = mn;
  if(lo == hi) return;
  int lmid = (lo+mid-1)/2, rmid = (mid+1+hi)/2;
  for(int i=mid;i>lmid;i--) {
    --freq[a[i-1]];
    curr -= freq[a[i-1]];
  }
  x = curr;
  solve(lo, mid-1, optl, best, k); //error here!
  for(int i=lmid+1;i<=rmid;i++) {
    curr += freq[a[i-1]];
    ++freq[a[i-1]];
  }
  for(int i=optl;i<best;i++) {
    --freq[a[i-1]];
    curr -= freq[a[i-1]];
  }
  x = curr;
  solve(mid+1, hi, best, optr, k);
  for(int i = rmid; i > mid; i--) {
    --freq[a[i-1]];
    curr -= freq[a[i-1]];
  }
  for(int i = best - 1; i >= optl; i--) {
    curr += freq[a[i-1]];
    ++freq[a[i-1]];
  }
  x = curr;
}
int main() {
  int n, k; cin >> n >> k;
  dp.resize(n+1, vector<ll>(k+1));
  for(int i=1;i<=n;i++) 
    dp[i][0] = 1e18;
  for(int j=1;j<=k;j++)
    dp[0][j] = 1e18;
  a.resize(n);
  freq.resize(n);
  for(auto &a : a) cin >> a, --a;
  for(int i=1;i<=k;i++) {
    freq.assign(n, 0);
    x = 0LL;
    for(int j=1;j<=(1+n)/2;j++) {
      x += freq[a[j-1]];
      ++freq[a[j-1]];
    }
    solve(1, n, 1, n, i);
  }
  cout << dp[n][k] << "\n";
}