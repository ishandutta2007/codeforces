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
int d[MX][2], u[MX][2];
int main() {
  int n; cin >> n;
  vector<int> p(n);
  for(auto &p : p) cin >> p;
  for(int i=0;i<n;i++) {
    d[i][0] = 1, u[i][0] = 1;
    if(i > 0 && p[i-1] < p[i]) d[i][0] = d[i-1][0] + 1;
    if(i > 0 && p[i-1] > p[i]) u[i][0] = u[i-1][0] + 1;
  }
  for(int i=n-1;i>=0;i--) {
    d[i][1] = 1, u[i][1] = 1;
    if(i < n-1 && p[i+1] < p[i]) d[i][1] = d[i+1][1] + 1;
    if(i < n-1 && p[i+1] > p[i]) u[i][1] = u[i+1][1] + 1;
  }
  multiset<int> in;
  for(int i=0;i<n;i++) {
    in.insert(u[i][0]);
    in.insert(u[i][1]);
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(d[i][0] == d[i][1] && d[i][0] % 2) {
      in.erase(in.lower_bound(d[i][0]));
      in.erase(in.lower_bound(d[i][1]));
      if(*in.rbegin()  < d[i][0])  ++ans;
      in.insert(d[i][0]);
      in.insert(d[i][1]);
    }
  }
  cout << ans << "\n";
}