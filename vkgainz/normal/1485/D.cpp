#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>

int main() {
  int n, m; cin >> n >> m;
  int a[n][m];
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  int lcm = 16*9*5*7*11*13;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if((i+j)%2==1) cout << lcm << " ";
      else cout << lcm+a[i][j]*a[i][j]*a[i][j]*a[i][j] << " ";
    }
    cout << "\n";
  }
}