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
vector<int> p;
int used;
int query(int t, int i, int j, int x) {
  ++used;
  cout <<"? " <<  t << " " << i+1 << " " << j+1 << " " << x << "\n";
  cout.flush();
  int ret; 
  cin >> ret;
  return ret;
}
int main() {
  //idea: find p_1 in 30 queries (15 x 2) since 2^15 > 10000
  //find each in avg 3*n/2 after that
  //profit
  int T; cin >> T;
  while(T--) {
    int n; cin >>  n;
    used = 0;
    int lo = 1, hi = n;
    vector<int> ans(n);
    int x = query(1, 1, 0, n-1);
    if(x == n) ans[0] = n;
    int y = query(2, 0, 1, 1);
    if(y == 1) ans[0] = 1;
    while(lo != hi) { //ch while testing
      int mid = (lo+hi)/2;
      int a = query(1, 0, 1, mid), b = query(2, 0, 1, mid);
      if(a == mid+1) {
        if(b <= mid) {
          hi = mid;
        }
        else {
          lo = b;
        }
      }
      else {
        //{x, min(p[i], x+1)} / {max(p[i], p[j]), x}
        //p[i] = x ==> 
        if(b == mid + 1) {
          lo = mid+1;
        }
        else {
          hi = mid;
        }
      }
    }
    if(ans[0] == 0)
      ans[0] = hi;
    int dropoff = (n+1)/2;
    for(int i=1;i<n;i++) {
      int a, b;
      if(ans[0] <= dropoff) {
        a = query(1, 0, i, n-1);
        if(a > ans[0]) ans[i] = a;
        else {
          b = query(2, i, 0, 1);
          ans[i] = b;
        }
      }
      else {
        b = query(2, i, 0, 1);
        if(b < ans[0]) ans[i] = b;
        else {
          a = query(1, 0, i, n-1);
          ans[i] = a;
        }
      }
    }
    cout << "! ";
    for(int i=0;i<n;i++) {
      cout << ans[i] << " ";
    }
    cout.flush();
    cout << "\n";
  }
}