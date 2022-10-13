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
  int n, q, k; cin >> n >> q >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  while(q--) {
    int l, r; cin >> l >> r;
    --l, --r;
    ll ans = a[r] - a[l] + k - 2*1LL*(r-l+1)+1;
    cout << ans << "\n";
  }
}