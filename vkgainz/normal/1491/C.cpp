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
    vector<int> S(n);
    vector<int> num(n);
    for(auto &a : S) cin >> a;
    for(auto &x : num) x = 0;
    ll ans = 0;
    for(int i=0;i<n;i++) {
      for(int j=2;j<=min(S[i], n);j++) {
        if(i+j < n) ++num[i+j];
      }
      if(num[i] >= S[i] && i+1 < n) {
        num[i+1] += num[i] - S[i] + 1;
      }
      S[i] -= num[i];
      S[i] = max(S[i], 1);
      ans += S[i] - 1;
    }
    cout << ans << "\n";
  }
}