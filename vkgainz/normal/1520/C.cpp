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
    vector<int> o, e;
    for(int i=1;i<=n*n;i++) {
      if(i%2) o.push_back(i);
      else e.push_back(i);
    }
    if(n == 2) {
      cout << -1 << "\n";
      continue;
    }
    int ans[n][n];
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(!o.empty()) ans[i][j] = o.back(), o.pop_back();
        else ans[i][j] = e.back(), e.pop_back();
      }
    }
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
}