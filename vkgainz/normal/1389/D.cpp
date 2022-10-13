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
int main() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int intersection = min(r1, r2) - max(l1, l2);
    int len = max(r1, r2) - min(l1, l2);
    if(intersection >= 0) {
      ll st = intersection*1LL*n, en = len*1LL*n;
      if(st < k) {
        if(en >= k) cout << k - st << "\n";
        else cout << en - st + (k - en) * 1LL * 2 << "\n";
      }
      else cout << 0 << "\n";
    }
    else {
      //extend first i
      ll ans = 1e18;
      int toZero = -intersection;
      ll curr = 0LL;
      for(int i=1;i<=n;i++) {
        curr = toZero*1LL*i;
        if(len*1LL*i >= k) {
          curr += k;
        }
        else {
          curr += len*1LL*i + (k - len*1LL*i)*2;
        }
        ans = min(ans, curr);
      }
      cout << ans << "\n";
    }
  }
}