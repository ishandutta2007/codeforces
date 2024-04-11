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

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    map<int, ll> sum;
    ll ans = 0LL;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      ans += (n - i)*1LL*sum[x];
      sum[x] += i + 1;
    }
    cout << ans << "\n";
  }
}