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
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &a : a) cin >> a;
    for(auto & b : b) cin >> b;
    int ans = 0;
    for(int i=0;i<2;i++) {
      int x = upper_bound(a.begin(), a.end(), 0) - a.begin();
      int y = upper_bound(b.begin(), b.end(), 0) - b.begin();
      int curr = 0;
      for(int j=y;j<m;j++) {
        curr += binary_search(a.begin(), a.end(), b[j]);
      }
      int ret = curr;
      for(int j=y;j<m;j++) {
        curr -= binary_search(a.begin(), a.end(), b[j]);
        int r = (upper_bound(a.begin(), a.end(), b[j])  - a.begin()) - x;
        int s = lower_bound(b.begin(), b.end(), b[j] - r + 1) - b.begin();
        ret = max(ret, curr + j - s + 1);
      }
      ans += ret;
      for(auto &a : a) a = -a;
      for(auto &b : b) b = -b;
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
    }
    cout << ans << "\n";
  }
}