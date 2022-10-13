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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto &a : a) cin >> a;
  vector<vector<int>> dp(n, vector<int>(19));
  vector<vector<int>> dp2(19, vector<int>(19));
  for(auto &a : dp) for(auto &a : a) a = 1000000;
  for(auto &a : dp2) for(auto &a : a) a = 1000000;
  for(int i=n-1;i>=0;i--) {
    for(int bit=0;bit<19;bit++) {
      if(a[i]&(1<<bit)) {
        dp[i][bit] = i;
        for(int j=0;j<19;j++) {
          dp[i][j] = min(dp[i][j], dp2[bit][j]);
        }
      }
    }
    for(int bit=0;bit<19;bit++) {
      if(a[i]&(1<<bit)) {
        for(int j=0;j<19;j++) {
          dp2[bit][j] = min(dp2[bit][j], dp[i][j]);
        }
      }
    }
  }
  while(q--) {
    int x, y; cin >> x >> y;
    --x, --y;
    bool work = false;
    for(int bit=0;bit<19;bit++) {
      if(a[y]&(1<<bit)) {
        if(dp[x][bit] <= y) work = true;
      }
    }
    if(work) cout << "Shi" << "\n";
    else cout << "Fou" << "\n";
  }
}