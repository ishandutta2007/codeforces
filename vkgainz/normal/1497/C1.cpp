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
    int n, k; cin >> n >> k;
    if(n%2) {
      cout << 1 << " " << (n-1)/2 << " " << (n-1)/2 << "\n";
    }
    else {
      if(n%4==0) cout << n/2 << " " << n/4 << " " << n/4 << "\n";
      else cout << 2 << " " << (n-2)/2 << " " << (n-2)/2 << "\n";
    }
  }
}