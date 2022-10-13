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
    int sec = -1;
    vector<int> left;
    for(int i=0;i<n-1;i++) {
      left.push_back(i);
      cout << "? " << left.size() << " " << 1 << "\n";
      for(auto &a : left) cout << a+1 << " ";
      cout << "\n";
      cout << i+2 << "\n";
      int x; cin >> x;
      if(x != 0) {
        sec = i+1;
        break;
      }
    }
    int lo = 0, hi = sec - 1; //[lo, hi]
    while(lo<hi) {
      int mid = (lo+hi)/2;
      cout << "? " << mid+1 << " " << 1 << "\n";
      for(int i=0;i<=mid;i++) cout << i+1 << " ";
      cout << "\n";
      cout << sec+1 << "\n";
      int x; cin >> x;
      if(x == 0) {
        lo = mid + 1;
      }
      else {
        hi = mid;
      }
    }
    vector<int> ans;
    for(int i=0;i<lo;i++) {
      ans.push_back(i);
    }
    for(int i=lo+1;i<sec;i++) {
      ans.push_back(i);
    }
    for(int i=sec+1;i<n;i++) {
      cout << "? " << 1 << " " << 1 << "\n";
      cout << sec+1 << "\n";
      cout << i+1 << "\n";
      int x; cin >> x;
      if(x == 0) ans.push_back(i);
    }
    cout << "! " << ans.size() << " ";
    for(auto &a : ans) cout << a+1 << " ";
    cout << "\n";
  }
}