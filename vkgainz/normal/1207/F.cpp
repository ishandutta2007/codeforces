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
const int BLOCK_SZ = 707;
vector<vector<int>> adj;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q; cin >> q;
  vector<int> a;
  a.assign(500001, 0);
  vector<vector<int>> sum(BLOCK_SZ + 1, vector<int>(BLOCK_SZ));
  while(q--) {
    int t, x, y; cin >> t >> x >> y;
    if(t == 1) {
      a[x] += y;
      for(int i=1;i<=BLOCK_SZ;i++) {
        sum[i][x%i] += y;
      }
    }
    else {
      int ans = 0LL;
      if(x > BLOCK_SZ) {
        for(int i=0;i*x + y <= 500000;i++) {
          ans += a[i*x+y];
        }
      }
      else {
        ans = sum[x][y];
      }
      cout << ans << "\n";
    }
  }
}