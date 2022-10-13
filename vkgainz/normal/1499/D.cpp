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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e7 + 5;
bool prime[MX];
int num[MX];
int solve(int c, int d, int x, int k) {
  ll left = d*1LL*k + x;
  ll right = c*1LL*k;
  if(left%right) return 0;
  left /= right;
  return 1<<num[left];
}
int main() {
  memset(prime, 1, sizeof(prime));
  for(int i=2;i<MX;i++) {
    if(!prime[i]) continue;
    for(int j=1;j*i<MX;j++) {
      prime[i*j] = false;
      ++num[i*j];
    }
  }
  int t; cin >> t;
  while(t--) {
    int c, d, x; cin >> c >> d >> x;
    ll ans = 0LL;
    for(int i=1;i<=sqrt(x);i++) {
      if(x%i==0) {
        ans += solve(c, d, x, i);
        if(i*i==x) {
          continue;
        }
        ans += solve(c, d, x, x/i);
        //solve for x/i
      }
    }
    cout << ans << "\n";
  }
}