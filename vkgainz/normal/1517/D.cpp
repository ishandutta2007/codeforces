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
int dp[501][501][21];
int main() {
  int n, m, k; cin >> n >> m >> k;
  int a[n][m-1], b[n-1][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m-1;j++)
      cin >> a[i][j];
  for(int i=0;i<n-1;i++)
    for(int j=0;j<m;j++)
      cin >> b[i][j];
  if(k%2) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        cout << -1 << " ";
      }
      cout << "\n";
    }
    return 0;
  }
  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};
  for(int x=1;x<=k/2;x++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {

        dp[i][j][x] = 1000000000;
        for(int r=0;r<4;r++) {
          int nx = i + dx[r], ny = j + dy[r];
          if(nx >= 0 && ny >=0 && nx < n && ny < m) {
            int w;
            if(r == 0) w = a[i][ny];
            else if(r == 2) w = a[i][j];
            else if(r == 1) w = b[i][j];
            else w = b[nx][j];
            dp[i][j][x] = min(dp[i][j][x], dp[nx][ny][x-1] + w);
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout << dp[i][j][k/2]*2 << " ";
    }
    cout << "\n";
  }
}