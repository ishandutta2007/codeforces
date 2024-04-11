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
    int n; cin >> n;
    bool sort = true;
    vector<int> a(n);
    for(auto &a : a) cin >> a;
    for(int i = 0; i < n; i++) {
      if(a[i] != i + 1) sort = false;
    }
    if(sort) cout << 0 << "\n";
    else {
      if(a[0] == 1 || a[n-1] == n) cout << 1 << "\n";
      else if(a[0] == n && a[n - 1] == 1) {
        cout << 3 << "\n";
      }
      else cout << 2 << "\n";
    }
  }
}