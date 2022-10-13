#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int main() {
  int t; cin >> t;
  while(t--) {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> in(n);
    int mxChange = 0, mxD = 0;
    for(int i=0;i<n;i++) {
      cin >> in[i].f >> in[i].s;
      mxD = max(mxD, in[i].f);
      mxChange = max(mxChange, in[i].f - in[i].s);
    }
    if(mxChange<=0) {
      if(mxD >= x) {
        cout << 1 << "\n";
      }
      else cout << -1 << "\n";
    }
    else {
      int a = max(0, (int)ceil((x-mxD)*1.0/mxChange));
      cout << a+1 << "\n";
    }
  }
}