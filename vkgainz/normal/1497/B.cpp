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
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> f(m);
    for(auto &a : a) {
      cin >> a;
      ++f[a%m];
    }
    int ans = 0;
    for(int i=0;i<=m;i++) {
      if(f[i%m] == 0 && f[(m-i)%m] == 0) continue;
      ans += max(1, abs(f[(i%m)] - f[(m-i)%m]));
    }
    if(m%2==0 && f[m/2]) ++ans;
    cout << ans/2 << "\n";
  }
}