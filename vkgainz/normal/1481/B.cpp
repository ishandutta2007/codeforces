#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    int ans = -1;
    for(int i=1;i<=10005;i++) {
      //simulate
      for(int j=0;j<n-1;j++) {
        if(h[j]>=h[j+1]) continue;
        else {
          ++h[j];
          if(i == k) ans = j+1;
          break;
        }
      }
    }
    cout << ans << "\n";
  }
}