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
int main() {
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  for(int msk=0;msk<1<<n;msk++) {
    int dif = 0;
    for(int i=0;i<n;i++) {
      if(msk&(1<<i)) dif += a[i];
      else dif -= a[i];
    }
    dif += 360*15;
    if(dif%360 == 0) {
      cout << "YES" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
}