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

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m, x; cin >> n >> m >> x;
    vector<int> h(n);
    for(auto &h : h) cin >> h;
    multiset<pair<int, int>> in;
    vector<int> ans(n);
    for(int i=0;i<m;i++) 
      in.insert({h[i], i}), ans[i] = i;
    for(int i=m;i<n;i++) {
      auto it = in.begin();
      pair<int, int> x = *it;
      in.erase(in.begin());
      x.f += h[i];
      ans[i] = x.s;
      in.insert(x);
    }
    cout << "YES" << "\n";
    for(auto &a : ans) cout << a+1 << " ";
    cout << "\n";
  }
}