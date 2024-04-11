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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &a : a) cin >> a;
    vector<int> prev(n), nxt(n);
    set<int> toRemove;
    for(int i=0;i<n;i++) {
      if(__gcd(a[i], a[(i+n-1)%n]) == 1) {
        toRemove.insert(i);
      }
      prev[i] = (i+n-1)%n;
      nxt[i] = (i+1)%n;
    }
    vector<int> ans;
    int curr = 1;
    int numRemove = 0;
    while(!toRemove.empty() && numRemove < n) {
      if(toRemove.lower_bound(curr) == toRemove.end())
        curr = -1;
      auto it = toRemove.lower_bound(curr);
      int idx = (*it);
      ans.push_back(idx);
      toRemove.erase(it);
      prev[nxt[idx]] = prev[idx];
      nxt[prev[idx]] = nxt[idx];
      ++numRemove;
      if(__gcd(a[nxt[idx]], a[idx]) == 1)
        toRemove.erase(nxt[idx]);
      if(__gcd(a[nxt[idx]], a[prev[idx]]) == 1)
        toRemove.insert(nxt[idx]);
      curr = nxt[idx] + 1;
    }
    cout << ans.size() << " ";
    for(auto &a : ans) cout << a+1 << " ";
    cout << "\n";
  }

}