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
#define vpi vector<pair<int, int>>
#define vvpi vector<vpi>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 400005;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vi a(n);
    for(auto &a : a) cin >> a;
    vvi cost(n, vi(n));
    for(int i=0;i<n;i++) {
      ordered_set in;
      for(int j=i+1;j<n;j++) {
        cost[i][j] = in.size() - in.order_of_key({j, -10000});
        in.insert({j+a[j], j});
      }
    }
    vvi dp(n);
    for(int i=0;i<n;i++) {
      dp[i].resize(n, 1000000);
    }
    vvi en(n);
    for(int i=0;i<n;i++) {
      en[a[i]+i].pb(i);
    }
    for(int j=n-1;j>=0;j--) {
      int best = 100000;
      for(int k=a[j] + j; k >= j; k--) {
        for(auto &it : en[k]) {
          if(j == n-1)
            dp[it][j] = cost[it][j];
          else
            dp[it][j] = min(dp[it][j], cost[it][j] + best);
        }
        best = min(best, dp[j][k]);
      }
    }
    int ans = 1000000;
    for(int i=0;i<n;i++) {
      ans = min(ans, dp[0][i]);
    }
    cout << ans << "\n";
  }
}