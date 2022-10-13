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
int dp[251][251][251];
int main() {
  int n, q; cin >> n >> q;
  string x, y, z;
  string w; cin >> w;
  for(int i=0;i<=250;i++) {
    for(int j=0;j<=250;j++) {
      for(int k=0;k<=250;k++) {
        dp[i][j][k] = n+1;
      }
    }
  }
  dp[0][0][0] = 0;
  int nxt[n+2][26];
  //nxt greater than i
  int lst[26];
  for(int i=0;i<26;i++) lst[i] = n+1;
  for(int i=n+1;i>=0;i--) {
    for(int j=0;j<26;j++) nxt[i][j] = lst[j];
    if(i>0 && i<=n)
      lst[w[i-1]-'a'] = i;
  }
  for(int i=0;i<q;i++) {
    char t;
    cin >> t;
    if(t == '+') {
      int e;
      char add; cin >> e >> add;
      --e;
      //recalculate dp...!
      if(e == 0) {
        x += add;
        for(int a=x.length(); a<=x.length(); a++) {
          for(int b=0;b<=y.length();b++) {
            for(int c=0;c<=z.length();c++) {
              dp[a][b][c] = n+1;
              if(a>0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a-1][b][c]][x[a-1]-'a']);
              }
              if(b > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b-1][c]][y[b-1]-'a']);
              }
              if(c > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b][c-1]][z[c-1]-'a']);
              }
            }
          }
        }
      }
      else if(e == 1) {
        y += add;
        for(int a=0; a<=x.length(); a++) {
          for(int b=y.length();b<=y.length();b++) {
            for(int c=0;c<=z.length();c++) {
              dp[a][b][c] = n+1;
              if(a>0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a-1][b][c]][x[a-1]-'a']);
              }
              if(b > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b-1][c]][y[b-1]-'a']);
              }
              if(c > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b][c-1]][z[c-1]-'a']);
              }
            }
          }
        }
      }
      else {
        z += add;
        for(int a=0; a<=x.length(); a++) {
          for(int b=0;b<=y.length();b++) {
            for(int c=z.length();c<=z.length();c++) {
              dp[a][b][c] = n+1;
              if(a>0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a-1][b][c]][x[a-1]-'a']);
              }
              if(b > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b-1][c]][y[b-1]-'a']);
              }
              if(c > 0) {
                dp[a][b][c] = min(dp[a][b][c], nxt[dp[a][b][c-1]][z[c-1]-'a']);
              }
            }
          }
        }
      }
    }
    else {
      int e; cin >> e;
      --e;
      if(e == 0) {
        x = x.substr(0, x.length() - 1);
      }
      else if(e == 1) {
        y = y.substr(0, y.length() - 1);
      }
      else {
        z = z.substr(0, z.length() - 1);
      }
    }
    if(dp[x.length()][y.length()][z.length()] <= n) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}