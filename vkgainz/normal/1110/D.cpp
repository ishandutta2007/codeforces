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
int dp[1000001][3][3];
int main() {
  int n, m; cin >> n >> m;
  vi a(n), f(m);
  for(int i=0;i<n;i++) {
    cin >> a[i];
    ++f[--a[i]];
  }
  for(int i=0;i<m;i++) {
    for(int j=0;j<3;j++) {
      for(int k=0;k<3;k++) {
        dp[i][j][k] = -1000000;
        for(int make=0;make<3;make++) {
          if(f[i] >= j+k+make) {
            if(i == 0) dp[i][j][k] = max(dp[i][j][k], (f[i] - (j+k+make))/3 + k);
            else  
              dp[i][j][k] = max(dp[i][j][k], dp[i-1][make][j] + (f[i] - (j+k+make))/3 + k);
          }
        }
      }
    }
  }
  cout << dp[m-1][0][0];
}