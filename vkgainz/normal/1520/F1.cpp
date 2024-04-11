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
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 400005;
int main() {
  int n, t; cin >> n >> t;
  while(t--) {
    int k; cin >> k;
    int lo = 1, hi = n;
    for(int j=0;j<20;j++) {
      int mid = (lo+hi)/2;
      int x;
      cout << "? " << 1 << " " << mid << "\n";
      cout.flush();
      cin >> x;
      int numZero =mid - x;
      if(numZero < k) 
        lo = mid + 1;
      else
        hi = mid;
    }
    cout << "! " << lo << "\n";
    cout.flush();
  }
}