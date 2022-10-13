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
  int q; cin >> q;
  while(q--) {
    string s, t; cin >> s >> t;
    int ans = -1;
    for(int lcm=30;lcm>=1;lcm--) {
      string x = "";
      for(int i=1;i<=lcm;i++) {
        x+=s;
      }
      if(x.size()%t.size()==0) {
        bool work = true;
        for(int i=0;i<x.size()/t.size();i++) {
          if(x.substr(t.size()*i, t.size()) == t) {
            continue;
          }
          else work = false;
        }
        if(work) ans = lcm;
      }
      else continue;
    }
    if(ans==-1) cout << -1 << "\n";
    else {
      string ret;
      for(int i=1;i<=ans;i++) ret+=s;
      cout << ret << "\n";
    }
  }
}