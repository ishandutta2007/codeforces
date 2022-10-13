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
const int MX = 1e6 + 5;
vector<pair<int, ll>> store;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  vector<vector<int>> ans(n, vector<int>(n));
  for(int i=0;i<n;i++) {
    int x = i, y = i;
    for(int j=0;j<p[i]-1;j++) {
      ans[x][y] = p[i];
      if(y && ans[x][y-1] == 0)
        --y;
      else
        ++x;
    }
    ans[x][y] = p[i];
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<=i;j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}