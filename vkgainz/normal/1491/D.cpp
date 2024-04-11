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
int sz;
vector<int> seg;
int main() {
  int q; cin >> q;
  while(q--) {
    int u, v; cin >> u >> v;
    int x = 0, y = 0;
    bool work = u <= v;
    for(int i=0;i<30;i++) {
      if(u&(1<<i)) ++x;
      if(v&(1<<i)) ++y;
      if(x < y) work = false;
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}