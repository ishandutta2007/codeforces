#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second


int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int b[n];
    for(int i=0;i<n;i++)
      cin >> b[i], --b[i];
    int mn = 0, mx = 0;
    set<int> s;
    for(int i=0;i<2*n;i++)
      s.insert(i);
    for(int i=0;i<n;i++) {
      s.erase(b[i]);
    }
    for(int i=0;i<n;i++) {
      auto it = s.upper_bound(b[i]);
      if(it!=s.end()) {
        s.erase(it);
        ++mx;
      }
      else {
        s.erase(s.begin());
      }
    }
    for(int i=0;i<2*n;i++)
      s.insert(i);
    for(int i=0;i<n;i++) {
      s.erase(b[i]);
    }
    for(int i=n-1;i>=0;i--) {
      auto it = s.lower_bound(b[i]);
      if(it==s.begin()) {
        ++mn;
        s.erase(it);
      }
      else {
        --it;
        s.erase(it);
      }
    }
    cout << mx-mn+1 << "\n";
  }
}