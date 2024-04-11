#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second

typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 5e5 + 5;

int main() {
  int t; cin >> t;
  while(t--) {
    int x, y; cin >> x >> y;
    vector<int> num(100001);
    //num such that x/k = i, 2 <= k <= x
    for(int j=1;j<=100000;j++) {
      int lo, hi;
      hi = min(y, x/j - 1);
      lo = max(100000, x/(j+1));
      if(hi >= lo) {
        num[j] += hi-lo+1;
      }
    }
    ll ans = 0LL;
    for(int i=1;i<=min(y, 100000-1);i++) {
      ans+=min(i-1, x/(i+1));
    }
    for(int j=1;j<=100000;j++) {
      ans+=num[j]*1LL*j;
    }
    cout << ans << "\n";
  }
}