#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5+ 5;
int dp[5001][5001];
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> sum(n);
  sum[0] = a[0];
  for(int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  vector<int> stack_on, stack_off;
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) stack_off.push_back(i); // = 0
    else stack_on.push_back(i); // = 1
  }
  for(int i = 0; i <= 5000; i++) {
    for(int j = 0; j <= 5000; j++) {
      if(j < i) dp[i][j] = 1000000000;
      else if(i > stack_on.size() || j > stack_off.size()) {
        dp[i][j] = 1000000000;
      }
      else {
        if(i == 0) dp[i][j] = 0;
        else {
          dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(stack_on[i - 1] - stack_off[j - 1]));
        }
      }
    }
  }
  cout << dp[stack_on.size()][stack_off.size()];
}