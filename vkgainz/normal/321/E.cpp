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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
vector<vector<int>> c;
vector<vector<int>> dp;
void fastscan(int &number) {
  register int c;
  number = 0;
  c = getchar();
  for(; (c>47 && c<58); c = getchar())
    number = number *10 + c - 48;
}
void solve(int lo, int hi, int optl, int optr, int k) {
  if(lo > hi) return;
  int mid = (lo + hi)/2;
  int best = optl;
  int mn = 1e9;
  for(int i = optl; i <= min(optr, mid); i++) {
    if(c[i][mid] + dp[i-1][k-1] < mn) {
      mn = c[i][mid] + dp[i-1][k-1];
      best = i;
    }
  }
  dp[mid][k] = mn;
  solve(lo, mid - 1, optl, best, k), solve(mid + 1, hi, best, optr, k);
}
int main() {
  int n, k;
  fastscan(n), fastscan(k);
  vector<vector<int>> u(n, vector<int>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      fastscan(u[i][j]);
  c.resize(n+1, vector<int>(n+1));
  for(int len=1;len<=n;len++) {
    for(int i=1;i+len-1<=n;i++) {
      if(len == 1) {
        c[i][i] = 0;
      }
      else {
        int j = i+len-1;
        c[i][j] = c[i][j-1] + c[i+1][j] + u[i-1][j-1] - c[i+1][j-1];
      }
    }
  }
  dp.resize(n+1, vector<int>(k+1));
  for(int i=1;i<=n;i++)
    dp[i][0] = 1e9;
  for(int i=1;i<=k;i++) {
    solve(1, n, 1, n, i);
  }
  cout << dp[n][k] << "\n";
}