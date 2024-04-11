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
  int n; cin >> n;
  int temp = n;
  vector<int> in;
  while(n>0) {
    in.push_back(n%10);
    n/=10;
  }
  n = temp;
  int ans = 100000000;
  for(int sq=1;sq<=100000;sq++) {
    if(sq*1LL*sq <= n) {
      int x = sq*sq;
      vector<int> dig;
      while(x>0) {
        dig.push_back(x%10);
        x/=10;
      }
      int j =0;
      for(int i=0;i<in.size();i++) {
        if(j<dig.size() && in[i] == dig[j]) {
          ++j;
        }
      }
      if(j == dig.size()) {
        ans = min(ans, (int) (in.size() - dig.size()));
      }
    }
  }
  if(ans == 100000000) cout << -1 << "\n";
  else cout << ans << "\n";
}