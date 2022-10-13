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
    int n; cin >> n;
    vector<int> c(n);
    for(auto &a : c) cin >> a;
    ll ans = 1e18;
    ll m1 = 1e18, m2 = 1e18;
    int x = 0, y = 0;
    ll sum1 = 0LL;
    ll sum2 = 0LL;
    for(int i=0;i<n;i++) {
      if(i%2) {
        sum2 += c[i];
        m2 = min(m2, 1LL*c[i]);
        ++y;
      }
      else {
        sum1 += c[i];
        m1 = min(m1, 1LL*c[i]);
        ++x;
      }
      if(i==0) continue;
      ll curr = sum1 + (n-x)*1LL*(m1);
      curr += sum2 + (n-y)*1LL*(m2);
      ans = min(ans, curr);
    }
    cout << ans << "\n";
  }
}