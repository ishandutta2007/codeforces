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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int best = 0;
    for(int i=0;i<n;i++) {
      if(a[i] < a[best]) best = i;
    }
    cout << n-1 << "\n";
    for(int i=best-1;i>=0;i--) {
      cout << best+1 << " " << i+1 << " " << a[best] << " " << a[best]+(best-i)%2 << "\n";
    }
    for(int i=best+1;i<n;i++) {
      cout << best+1 << " " << i+1 << " " << a[best] << " " << a[best] + (i-best) << "\n";
    }
  }
}