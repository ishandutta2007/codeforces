#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    int sum = 0;
    for(int i=0;i<n;i++)
      sum+=a[i];
    int ans = -1;
    for(int spl=1;spl<=n;spl++) {
      if(sum%spl!=0) continue;
      int mk = sum/spl;
      int sum = 0;
      int cnt = 0;
      bool w = true;
      for(int i=0;i<n;i++) {
        sum+=a[i];
        if(sum==mk) {
          ++cnt;
          sum = 0;
        }
        else if(sum>mk) {
          w = false;
          break;
        }
      }
      if(sum!=0 || cnt!=spl) w = false;
      if(w) ans = n-spl;
    }
    cout << ans << "\n";
  }
}