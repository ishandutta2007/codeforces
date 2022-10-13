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
  int n, m; cin >> n >> m;
  ll fact[n+1];
  fact[0] = 1LL;
  for(int i=1;i<=n;i++) fact[i] =fact[i-1]*1LL*i % m;
  ll ans = 0LL;
  for(int k=0;k<n;k++) {
    ans += fact[n-k]*1LL*(n-k)%m*fact[k+1]%m;
    ans %= m;
  }
  if(ans<0) ans += m;
  cout << ans << "\n";
}