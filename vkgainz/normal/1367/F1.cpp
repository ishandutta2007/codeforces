#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vpi vector<pair<int, int>>
#define vvpi vector<vpi>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 400005;
const double PI = acos(-1);

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> occ;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      occ[a[i]] = i;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<int> dp(n);
    for(int i = n - 1; i >= 0; i--) {
      if(i == n - 1) dp[i] = 1;
      else {
        if(occ[a[i]] < occ[a[i+1]])
          dp[i] = dp[i + 1] + 1;
        else
          dp[i] = 1;
      }
      ans = max(ans, dp[i]);
    }
    cout << n - ans << "\n";
  }
}