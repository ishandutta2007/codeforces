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
ll dp[1000001];
int divisors[1000001];
ll MOD = 998244353;
int main() {
  int n; cin >> n;
  dp[0] = 1LL;
  for(int i = 1; i <= 1000000; i++) {
    for(int j = i; j <= 1000000; j += i)
      ++divisors[j];
  }
  ll sum = dp[0];
  for(int i = 1; i <= 1000000; i++) {
    dp[i] = sum + divisors[i] - 1;
    dp[i] %= MOD;
    sum += dp[i];
    sum %= MOD;
  }
  if(dp[n] < 0) dp[n] += MOD;
  cout << dp[n] << "\n";
}