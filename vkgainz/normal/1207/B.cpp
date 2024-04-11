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
const int MX = 2e5 + 5;
int main() {
  int n, m; cin >> n>> m;
  int a[n][m];
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> ans;
  int b[n][m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) b[i][j] =  0;
  for(int i=0;i<n-1;i++) {
    for(int j=0;j<m-1;j++) {
      if(a[i][j] == 1 && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1) {
        ans.push_back({i, j});
        b[i][j] = 1, b[i][j+1] = 1, b[i+1][j] = 1, b[i+1][j+1] = 1;
      }
    }
  }
  bool work = true;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      work = work && b[i][j] == a[i][j];
    }
  }
  if(!work) cout << -1 << "\n";
  else {
    cout << ans.size() << "\n";
    for(auto &a : ans) cout << a.f+1 << " " << a.s+1 << "\n";
  }
}